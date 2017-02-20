#include "Sphere.h"

Sphere::Sphere(glm::mat4 transformation, float scale) : SceneNode(transformation, scale) {
}

Sphere::Sphere(glm::mat4 aTransformation, float scale, GLfloat xRot, GLfloat yRot) : SceneNode(aTransformation, scale) {
	xRotated = xRot, yRotated = yRot;
}

void Sphere::draw(float scale) {
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glutWireSphere(scale, 20, 20);
	glEnd();            // End Drawing The Sphere
}


