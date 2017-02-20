#include "3Dcar.h"

Car::Car(glm::mat4 aTransformation, float scale, int orient) : SceneNode(aTransformation, scale, orient) {
	orientation = orient;
}

void Car::draw(float scale) {
	float bodyOffset = scale / 2.0f;
	Cube body = Cube(glm::translate(glm::mat4(4.0), glm::vec3(0, 0, scale)), scale, orientation, orientation);
	body.setColor(0.3f, 0.9f, 0.4f);
	Cube bodyBack = Cube(glm::translate(glm::mat4(1.0), glm::vec3(0, 0, scale)), scale, orientation, orientation);
	bodyBack.setColor(0.3f, 0.9f, 0.4f);
	Cone bodyFront = Cone(glm::translate(glm::mat4(4.0), glm::vec3(0, 0, scale + scale)), scale, orientation, orientation);
	bodyFront.setColor(1, 1, 0);

	float wheel_offset = scale / 2.0f;
	Sphere w1 = Sphere(glm::translate(glm::mat4(4.0), glm::vec3(-wheel_offset, -wheel_offset, scale - 0.15)), scale / 3.0f);
	w1.setColor(0, 1, 1);


	Sphere w2 = Sphere(glm::translate(glm::mat4(10.0), glm::vec3(wheel_offset, -wheel_offset, scale - 0.15)), scale / 3.0f, 0, 0, false);
	w2.setColor(0, 1, 1);


	Sphere w3 = Sphere(glm::translate(glm::mat4(10.0), glm::vec3(-wheel_offset, -wheel_offset, scale + 0.1)), scale / 3.0f, 0, 0, false);
	w3.setColor(0, 0.4f, 1.0f);

	Sphere w4 = Sphere(glm::translate(glm::mat4(10.0), glm::vec3(wheel_offset, -wheel_offset, scale + 0.1)), scale / 3.0f, 0, 0, false);
	w4.setColor(0, 0.4f, 1.0f);

	body.addChild(&bodyBack);
	body.addChild(&bodyFront);
	body.addChild(&w1);
	body.addChild(&w2);
	body.addChild(&w3);
	body.addChild(&w4);

	body.render();
}
