#pragma once

#include "SceneNode.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"

#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>

class Car : public SceneNode {
public:
	Car::Car(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};