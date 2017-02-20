#include "SceneNode.h"
#pragma once
///////////////////////////////////////////////////////////////////////
//
// SceneNode.cpp
//
///////////////////////////////////////////////////////////////////////
using namespace std;

SceneNode::SceneNode(glm::mat4 aTransformation, float aScale) {
	transformation = aTransformation;
	parent = nullptr;
	children = std::vector<SceneNode*>();
	scale = aScale;
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
}

SceneNode::SceneNode(glm::mat4 aTransformation, float aScale, int orient) {
	transformation = aTransformation;
	//rotation = aRotation;
	parent = nullptr;
	children = std::vector<SceneNode*>();
	scale = aScale;

	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
}

void SceneNode::setColor(float R, float G, float B) {
	r = R;
	g = G;
	b = B;
}

void SceneNode::setParent(SceneNode* p) {
	parent = p;
}

void SceneNode::addChild(SceneNode* child) {
	children.push_back(child);
	(*child).setParent(this);

}

glm::mat4 SceneNode::getTransformationMatrix() {
	return transformation;
}

glm::quat SceneNode::getRotationQuat() {
	return rotation;
}

std::vector<SceneNode*> SceneNode::getChildren() {
	return children;
}
SceneNode* SceneNode::getParent() {
	return parent;
}

void SceneNode::render() {
	//glMatrixMode(GL_MODELVIEW);
	//rotation = 
	//Step One: getMyTransformation
	glm::mat4 transf = getTransformationMatrix();
	glm::quat rotf = getRotationQuat();
	glm::vec3 myScale;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transf, myScale, rotf, translation, skew, perspective);

	//Step Two: glPushMatrix(My Transformation)
	glPushMatrix();
	float sqrtOfW = sqrt(1 - rotf.w * rotf.w);
	glRotatef(2 * acos(rotf.w), rotf.x / sqrtOfW, rotf.y / sqrtOfW, rotf.z / sqrtOfW);
	glTranslatef(translation.x, translation.y, translation.z);



	//Step Three: Draw myself
	glColor3f(r, g, b);
	draw(scale);


	//Step Four: Render My Children
	for (int i = 0; i < children.size(); i++) {
		SceneNode* tmp = children.at(i);
		(*tmp).render();
	}

	//Final Step: glPopMatrix()
	glPopMatrix();

	return;

}


