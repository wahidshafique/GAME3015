#pragma once
#include "SceneNode.h"


///////////////////////////////////////////////////////////////////////
//
// SceneNode.cpp
//
///////////////////////////////////////////////////////////////////////
using namespace std;

SceneNode::SceneNode(glm::mat4 aTransformation, SceneNode* aParent)
{
	transformation = aTransformation;
	parent = aParent;
	children = std::vector<SceneNode*>();
}

void SceneNode::setColor(float R, float G, float B)
{
	r = R;
	g = G;
	b = B;
}
void SceneNode::setParent(SceneNode* p)
{
	parent = p;
}

void SceneNode::addChild(SceneNode* child)
{
	children.push_back(child);
	(*child).setParent(this);

}

glm::mat4 SceneNode::getTransformationMatrix()
{
	return transformation;
}

std::vector<SceneNode*> SceneNode::getChildren()
{
	return children;
}
SceneNode* SceneNode::getParent()
{
	return parent;
}

/*
{
	//Just draw a quad up to a scale for now
	glBegin(GL_LINE_LOOP);
		glVertex2f(-scale/2, -scale/2);
		glVertex2f(scale/2, -scale/2);
		glVertex2f(scale/2, scale/2);
		glVertex2f(-scale/2, scale/2);
	glEnd();
}
*/