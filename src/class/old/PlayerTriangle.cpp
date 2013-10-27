/*
 * PlayerTriangle.cpp
 *
 *  Created on: 29/mar/2013
 *      Author: misterpup
 */

#include "PlayerTriangle.h"

PlayerTriangle::PlayerTriangle(float base, float height)
{
	this->base = base;
	this->height = height;
}

PlayerTriangle::~PlayerTriangle()
{

}

float PlayerTriangle::getBase()
{
	return base;
}

float PlayerTriangle::getHeight()
{
	return height;
}

//Draws Player
void PlayerTriangle::draw()
{
	float halfBase = base/2;
	float halfHeight = height/2;

	glBegin(GL_TRIANGLES);
		glVertex3f(-halfBase, -halfHeight, 0.0f);
		glVertex3f(halfBase, -halfHeight, 0.0f);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0f, halfHeight, 0.0f);
	glEnd();
}
