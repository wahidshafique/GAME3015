#include "3Dcar.h"

Car::Car(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale) {

}

void Car::draw(float scale) {
	Cube body = Cube(glm::mat4(1.0f), scale, 10, 40);
	body.setColor(r, g, b);
	//body.


	float wheel_offset = scale / 2.0f;
	Cube w1 = Cube(glm::translate(glm::mat4(4.0), glm::vec3(-wheel_offset, -wheel_offset, 0.0f)), scale / 5.0f);
	w1.setColor(r, g, b);

	Cube w2 = Cube(glm::translate(glm::mat4(10.0), glm::vec3(wheel_offset, wheel_offset, 0.0f)), scale / 2.0f);
	w2.setColor(r, g, b);
	Cube w3 = Cube(glm::translate(glm::mat4(3.0), glm::vec3(-wheel_offset, wheel_offset, 0.0f)), scale / 1.0f);
	w3.setColor(r, g, b);
	Cube w4 = Cube(glm::translate(glm::mat4(6.0), glm::vec3(wheel_offset, -wheel_offset, 0.0f)), scale / 4.0f);
	w4.setColor(r, g, b);

	body.addChild(&w1);
	body.addChild(&w2);
	body.addChild(&w3);
	body.addChild(&w4);

	body.render();
}
