#include "Square.h"
Square::Square(glm::mat4 transformation, float scale) : SceneNode(transformation, scale) {
}

void Square::draw(float scale) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(-scale / 2, -scale / 2);
	glVertex2f(scale / 2, -scale / 2);
	glVertex2f(scale / 2, scale / 2);
	glVertex2f(-scale / 2, scale / 2);
	glEnd();
}


