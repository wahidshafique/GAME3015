#include <math.h>
#include "GL\glut.h"
float rotation_angle = 0.0f;
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	//glColor3f(1.0, 1.0, 0.0);
	glLoadIdentity();             /* clear the matrix */


	//Working with camera and setting camera parameters

	//glFrustum(/* Left, Right, Up, Down*/-0.1, +0.1, -0.1, +0.1, /*near-plane, far-plane*/0.1, 3);
	//gluLookAt(/*location*/1, 1, 2, /*direction*/0, 0, 0, /*up vector*/ 1, 0, 0);

	//glTranslatef(0.5, 0, 0);
	//glRotatef(rotation_angle, 0, 0, 1);

	/*glBegin(GL_TRIANGLE_FAN);
	for (double i = 0; i < 2 * 3.141; i+=0.5)
	{
		glVertex2f(0.2*cos(i), 0.2*sin(i));
	}
	glEnd();
	*/
	
	//The following parameters have to be set for lighting
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	
	//Ambient Light
	GLfloat light1_ambient[] = { 1.0, 0.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);

	
	//Difuse: Positional Light (Spot Light)
	GLfloat spot_direction[] = { 0.0, 0.0, -1.0 }; //Direction of the spot light.
	GLfloat light1_position[] = { 0.0, 0.0, 1.0, 1.0 };	//Position of light
	GLfloat light1_diffuse[] = { 0.0, 0.0, 1.0, 1.0 }; //The color of this positional light

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 15);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
	

	//Diffuse: Directional Light
	
	GLfloat light2_direction[] = { 0.0, 0.0, 1.0, 0.0 };  //The last parameter is zero, so, this is a directional light and the first three parameters specify the direction of light.
	GLfloat light2_diffuse[] = { 0.0, 1.0, 0.0, 0.1 };	//The color of directional light
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT3, GL_POSITION, light2_direction);
	

	//Difuse: Adding another positional Light (Spot Light) to see the interaction of two spot lights
	GLfloat spot_direction_4[] = { 0.0, 0.0, -1.0 }; //Direction of the spot light.
	GLfloat light1_position_4[] = { 0.0, 0.0, 1.0, 1.0 };	//Position of light
	GLfloat light1_diffuse_4[] = { 1.0, 0.0, 1.0, 0.5 }; //The color of this positional light

	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 10);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, light1_diffuse_4);
	glLightfv(GL_LIGHT4, GL_POSITION, light1_position_4);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction_4);


	//Breaking down one square into so many squares.
	//This will increase the number of normals and makes the effect of light more realistic.
	//If you reduce the value of step into a smaller value, say 0.1, you will see that the light effect will be changed.
	float step = 0.001;
	for (float i = -0.5; i < 0.5; i += step)
	{
		for (float j = -0.5; j < 0.5; j += step)
		{
			glBegin(GL_QUADS);
				glNormal3f(0, 0, 1);
				glVertex2f(i, j);
				glVertex2f(i + step, j);
				glVertex2f(i + step, j + step);
				glVertex2f(i, j + step);
			glEnd();
		}
	}
	
	glFlush();
}


void drawCircle(float x, float y, float radius)
{
	//Draws a circle in the specified position on the screen
}

void myIdleFunc()
{
	rotation_angle += 0.01;
	glutPostRedisplay();
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