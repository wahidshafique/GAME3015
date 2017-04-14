
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include "GL\glut.h"

class SceneNode
{
	private:
	std::vector<SceneNode*> children;
	SceneNode* parent;
	glm::mat4 transformation;
	float r, g, b;


	public:
		//Constructor
		SceneNode(glm::mat4 transformation, SceneNode* parent);

		//Methods
		void addChild(SceneNode*);
		void setColor(float r, float g, float b);
		glm::mat4 getTransformationMatrix();
		std::vector<SceneNode*> getChildren();
		SceneNode* getParent();
		void setParent(SceneNode* p);
		virtual void render(float scale) = 0;



};