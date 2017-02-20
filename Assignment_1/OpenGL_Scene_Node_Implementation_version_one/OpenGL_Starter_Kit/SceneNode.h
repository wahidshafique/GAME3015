#ifndef SCENENODE_HEADER
#define SCENENODE_HEADER


#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include "GL\glut.h"

class SceneNode
{
	protected:
	std::vector<SceneNode*> children;
	SceneNode* parent;
	glm::quat rotation;
	glm::mat4 transformation;
	float r, g, b;
	float scale;


	public:
		//Constructor
		SceneNode(glm::mat4 transformation, float scale);

		//Methods
		void SceneNode::addChild(SceneNode*);
		void SceneNode::setColor(float r, float g, float b);
		glm::mat4 SceneNode::getTransformationMatrix();
		std::vector<SceneNode*> getChildren();
		SceneNode* SceneNode::getParent();
		void SceneNode::setParent(SceneNode* p);
		void SceneNode::render();
		virtual void SceneNode::draw(float scale) = 0;
		//virtual void SceneNode::rotate(glm::mat4 rotate) = 0;
		void rotate(float x, float y);
};
#endif // !SCENENODE_HEADER