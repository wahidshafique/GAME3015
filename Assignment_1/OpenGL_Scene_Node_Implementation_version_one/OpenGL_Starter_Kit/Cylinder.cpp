#include "Cylinder.h"
#define PI 3.1415926535897932384626433832795
Cylinder::Cylinder(glm::mat4 transformation, float scale) : SceneNode(transformation, scale) {
}

Cylinder::Cylinder(glm::mat4 aTransformation, float scale, GLfloat xRot, GLfloat yRot) : SceneNode(aTransformation, scale) {
	xRotated = xRot, yRotated = yRot;
}

void Cylinder::draw(float scale) {
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);

	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat height = scale;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.5;
	GLfloat radius = scale / 2;

	glBegin(GL_LINE_LOOP);
	angle = 0.0;

	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on top of cylinder */
	glColor3ub(119, 136, 153);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glEnd();
	/** Draw the circle on bottom of cylinder */
	glColor3ub(119, 136, 153);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height - scale);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();
}


