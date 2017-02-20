#pragma once

#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>

class Sphere : public SceneNode {
	GLfloat xRotated = 1.0, yRotated = 1.0;
public:
	Sphere::Sphere(glm::mat4 transformation, float scale);
	Sphere::Sphere(glm::mat4 transformation, float scale, GLfloat xRot, GLfloat yRot, bool isFill);
	void draw(float scale) override;
};