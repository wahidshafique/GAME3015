#include "Cube.h"

Cube::Cube(glm::mat4 transformation, float scale) : SceneNode(transformation, scale) {
}

Cube::Cube(glm::mat4 aTransformation, float scale, GLfloat xRot, GLfloat yRot) : SceneNode(aTransformation, scale) {
	xRotated = xRot, yRotated = yRot;
}

void Cube::draw(float scale) {
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);      
	glVertex3f(scale / 2, scale / 2, -scale / 2);    // Top Right Of The Quad (Top)
	glVertex3f(-scale / 2, scale / 2, -scale / 2);    // Top Left Of The Quad (Top)
	glVertex3f(-scale / 2, scale / 2, scale / 2);    // Bottom Left Of The Quad (Top)
	glVertex3f(scale / 2, scale / 2, scale / 2);    // Bottom Right Of The Quad (Top)
	glVertex3f(scale / 2, -scale / 2, scale / 2);    // Top Right Of The Quad (Bottom)
	glVertex3f(-scale / 2, -scale / 2, scale / 2);    // Top Left Of The Quad (Bottom)
	glVertex3f(-scale / 2, -scale / 2, -scale / 2);    // Bottom Left Of The Quad (Bottom)
	glVertex3f(scale / 2, -scale / 2, -scale / 2);    // Bottom Right Of The Quad (Bottom)
	glVertex3f(scale / 2, scale / 2, scale / 2);    // Top Right Of The Quad (Front)
	glVertex3f(-scale / 2, scale / 2, scale / 2);    // Top Left Of The Quad (Front)
	glVertex3f(-scale / 2, -scale / 2, scale / 2);    // Bottom Left Of The Quad (Front)
	glVertex3f(scale / 2, -scale / 2, scale / 2);    // Bottom Right Of The Quad (Front)
	glVertex3f(scale / 2, -scale / 2, -scale / 2);    // Top Right Of The Quad (Back)
	glVertex3f(-scale / 2, -scale / 2, -scale / 2);    // Top Left Of The Quad (Back)
	glVertex3f(-scale / 2, scale / 2, -scale / 2);    // Bottom Left Of The Quad (Back)
	glVertex3f(scale / 2, scale / 2, -scale / 2);    // Bottom Right Of The Quad (Back)
	glVertex3f(-scale / 2, scale / 2, scale / 2);    // Top Right Of The Quad (Left)
	glVertex3f(-scale / 2, scale / 2, -scale / 2);    // Top Left Of The Quad (Left)
	glVertex3f(-scale / 2, -scale / 2, -scale / 2);    // Bottom Left Of The Quad (Left)
	glVertex3f(-scale / 2, -scale / 2, scale / 2);    // Bottom Right Of The Quad (Left)
	glVertex3f(scale / 2, scale / 2, -scale / 2);    // Top Right Of The Quad (Right)
	glVertex3f(scale / 2, scale / 2, scale / 2);    // Top Left Of The Quad (Right)
	glVertex3f(scale / 2, -scale / 2, scale / 2);    // Bottom Left Of The Quad (Right)
	glVertex3f(scale / 2, -scale / 2, -scale / 2);    // Bottom Right Of The Quad (Right)
	glEnd();            // End Drawing The Cube
	//glFlush(); 
}


