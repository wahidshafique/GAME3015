#include "Sphere.h"
#define PI 3.1415926535897932384626433832795
Sphere::Sphere(glm::mat4 transformation, float scale) : SceneNode(transformation, scale) {
}

Sphere::Sphere(glm::mat4 aTransformation, float scale, GLfloat xRot, GLfloat yRot, bool isFill) : SceneNode(aTransformation, scale) {
	xRotated = xRot, yRotated = yRot;
	fill = isFill;
}

void Sphere::draw(float scale) {
	int lats = 10;
	int longs = 10;
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = PI * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);
		if (fill) {
			glBegin(GL_POLYGON);
		} else {
			glBegin(GL_LINE_LOOP);
		}
		for (j = 0; j <= longs; j++) {
			double lng = 2 * PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0 * scale, y * zr0 * scale, z0 * scale);
			glVertex3f(x * zr0 * scale, y * zr0 * scale, z0 * scale);
			glNormal3f(x * zr1 * scale, y * zr1 * scale, z1 * scale);
			glVertex3f(x * zr1 * scale, y * zr1 * scale, z1 * scale);

		}
		glEnd();            // End Drawing The Sphere
	}
}

