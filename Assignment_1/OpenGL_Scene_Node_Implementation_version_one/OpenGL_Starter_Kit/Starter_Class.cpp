#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Tank.h"
#include "3Dcar.h"



float rotation_angle = 0.0f;
float x, y = 0;


void myDisplay(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//show some of the basic shapes...
	Cube cube = Cube(glm::translate(glm::mat4(1.f), glm::vec3(0.5f, 0.f, 0.f)), 0.1, x * 12, y * 12);
	cube.render();

	Sphere sphere = Sphere(glm::translate(glm::mat4(1.f), glm::vec3(0.25f, 0.f, 0.f)), 0.1, x * 12, y * 12);
	sphere.render();

	Cylinder cylinder = Cylinder(glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 0.f)), 0.1, x * 12, y * 12);
	cylinder.render();

	Cone cone = Cone(glm::translate(glm::mat4(1.f), glm::vec3(-0.25f, 0.f, 0.f)), 0.1, x * 12, y * 12);
	cone.render();
	//Car redCar = Car(glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 0.f)), 0.1);
	//redCar.rotate(x, y);
	//redCar.draw(1);
	//redCar.
	//glm::Rot
	//redCar.setColor(1.0, 0.0, 0.0);
	//redCar.render();

	//Tank blueTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, y, 0)), 0.1);
	//blueTank.setColor(0.0, 0.0, 1.0);
	//blueTank.render();

	//Tank greenTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, -y, 0)), 0.1);
	//greenTank.setColor(0.0, 1.0, 0.0);
	//greenTank.render();

	//Tank whiteTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, -y, 0)), 0.1);
	//whiteTank.setColor(1.0, 1.0, 1.0);
	//whiteTank.render();


	//Tank bigTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, 0, 0)), 0.2);
	//bigTank.setColor(1.0, 0.0, 1.0);
	//bigTank.render();



	/*
	Square root = Square(glm::mat4(1.0f), 0.5);
	root.setColor(1.0, 1.0, 0.0);


	//Triangle t = Triangle(glm::rotate(glm::mat4(1.0), 30.0f, glm::vec3(0.0f, 0.0f, 1.0f)), 0.7);
	Triangle t = Triangle(glm::translate(glm::mat4(1.0), glm::vec3(0.5f, 0.5f, 0.0f)), 0.5);

	t.setColor(0.0, 1.0, 0.0);
	root.addChild(&t);

	//Triangle t2 = Triangle(glm::rotate(glm::mat4(1.0), 0.0f, glm::vec3(0.0f, 0.0f, 1.0f)), 0.3);
	Square t2 = Square(glm::translate(glm::mat4(1.0), glm::vec3(-0.5f, -0.5f, 0.0f)), 0.5);
	t2.setColor(1.0, 0.0, 0.0);
	root.addChild(&t2);

	Triangle t3 = Triangle(glm::translate(glm::mat4(1.0), glm::vec3(0.0f, -0.5f, 0.0f)), 0.1);
	t3.setColor(0.0, 0.0, 1.0);
	root.addChild(&t3);


	root.render();
	*/

	glFlush();
}


void myIdleFunc() {
	//rotation_angle += 0.01;
	x += 0.0001;
	y -= 0.0001;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdleFunc);
	glutMainLoop();
	return 0;
}