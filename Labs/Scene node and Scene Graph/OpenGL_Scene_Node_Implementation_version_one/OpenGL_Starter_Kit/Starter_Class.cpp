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