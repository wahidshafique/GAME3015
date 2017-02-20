#pragma once

#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>

class Cylinder : public SceneNode {
	GLfloat xRotated = 1.0, yRotated = 1.0;
public:
	Cylinder::Cylinder(glm::mat4 transformation, float scale);
	Cylinder::Cylinder(glm::mat4 transformation, float scale, GLfloat xRot, GLfloat yRot, bool isFill);
	void draw(float scale) override;
};