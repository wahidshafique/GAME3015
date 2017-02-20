#pragma once

#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>

class Cone : public SceneNode {
	GLfloat xRotated = 1.0, yRotated = 1.0;
public:
	Cone::Cone(glm::mat4 transformation, float scale);
	Cone::Cone(glm::mat4 transformation, float scale, GLfloat xRot, GLfloat yRot);
	void draw(float scale) override;
};