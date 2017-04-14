#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Tank.h"
#include "Camera.h"




float rotation_angle = 0.0f;
float x, y=0;
int oldTimeSinceStart = 0;

Camera* cam;
GLint windowWidth = 800;
GLint windowHeight = 600;

GLint midWindowX = windowWidth / 2;
GLint midWindowY = windowHeight / 2;

GLfloat fieldOfView = 45.0f;
GLfloat near = 0.1f;
GLfloat far = 150.0f;


void handleKeyPresses(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		cam->holdingForward = true;
	case 's':
		cam->holdingBackward = true;
	case 'a':
		cam->holdingLeftStrafe = true;
	case 'd':
		cam->holdingRightStrafe = true;
	default:
		//do nothing
		break;
	}
}

void handleKeyReleased(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		cam->holdingForward = false;
	case 's':
		cam->holdingBackward = false;
	case 'a':
		cam->holdingLeftStrafe = false;
	case 'd':
		cam->holdingRightStrafe = false;
	default:
		//do nothing
		break;
	}
}

void handleMouseMove(int button, int state, int x, int y)
{
	cam->handleMouseMove(x, y);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glRotatef(cam->getRotation().x, 1.0f, 0.0f, 0.0f);  
	glRotatef(cam->getRotation().y, 0.0f, 1.0f, 0.0f);
	glTranslatef(-cam->getPosition().x, -cam->getPosition().y, -cam->getPosition().z);

	Tank redTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0)), 0.1);
	redTank.setColor(1.0, 0.0, 0.0);
	redTank.render();

	Tank blueTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, y, 0)), 0.1);
	blueTank.setColor(0.0, 0.0, 1.0);
	blueTank.render();

	Tank greenTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, -y, 0)), 0.1);
	greenTank.setColor(0.0, 1.0, 0.0);
	greenTank.render();

	Tank whiteTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, -y, 0)), 0.1);
	whiteTank.setColor(1.0, 1.0, 1.0);
	whiteTank.render();


	Tank bigTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, 0, 0)), 0.2);
	bigTank.setColor(1.0, 0.0, 1.0);
	bigTank.render();

	glFlush();
}

void init()
{
	glViewport(0, 0, (GLsizei) windowWidth, (GLsizei) windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat aspectRatio = (windowWidth > windowHeight) ? float(windowWidth) / float(windowHeight) : float(windowHeight) / float(windowWidth);
	GLfloat fH = tan(float(fieldOfView / 360.0f * 3.14159f)) * near;
	GLfloat fW = fH * aspectRatio;
	//glFrustum(-fW, fW, -fH, fH, near, far);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myIdleFunc()
{
	//rotation_angle += 0.01;
	//x += 0.0001;
	//y -= 0.0001;
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	//cam->move(deltaTime);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdleFunc);

	glutKeyboardFunc(handleKeyPresses);
	glutKeyboardUpFunc(handleKeyReleased);
	glutMouseFunc(handleMouseMove);

	cam = new Camera(windowWidth, windowHeight);
	init();
	glutMainLoop();
	return 0;
}