#include <math.h>
#include "SceneNode.h"

float rotation_angle = 0.0f;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*
	SceneNode root = SceneNode(glm::mat4(1.0f), nullptr);
	
	glm::mat4 trs = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.5f, 0.0f));
	
	SceneNode child_one = SceneNode(trs, &root);

	root.addChild(&child_one);
	
	root.render(1.0f);

	std::vector<SceneNode*> children = root.getChildren();
	
	SceneNode* tmp_child = children.at(0);

	glm::mat4 transformation = (*tmp_child).getTransformationMatrix();

	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, rotation, translation, skew, perspective);
	
	
	glPushMatrix();
	glTranslatef(translation.x, translation.y, translation.z);

	
	(*tmp_child).render(0.2);

	glPopMatrix();
	

	*/

	glFlush();
}


void myIdleFunc()
{
	//rotation_angle += 0.01;
	//glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
	glClearColor(1.0, 0.0, 0.0, 0.0);
	
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdleFunc);
	glutMainLoop();
	return 0;
}