/*
 * World.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "World2D.h"

World2D::World2D(float sizeX, float sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

World2D::~World2D()
{
}

void World2D::draw()
{
	float lineWidth = 3.0f;
	glLineWidth(lineWidth);

	float westWorld = sizeX/2.0f;
	float eastWorld = -westWorld;
	float topWorld = sizeY/2.0f;
	float bottomWorld = -topWorld;


	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(eastWorld, topWorld, 0.0f);
	glVertex3f(westWorld, topWorld, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(eastWorld, bottomWorld, 0.0f);
	glVertex3f(westWorld, bottomWorld, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(westWorld, bottomWorld, 0.0f);
	glVertex3f(westWorld, topWorld, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(eastWorld, bottomWorld, 0.0f);
	glVertex3f(eastWorld, topWorld, 0.0f);

	glEnd();
}

float World2D::getSizeX()
{
	return sizeX;
}

float World2D::getSizeY()
{
	return sizeY;
}

