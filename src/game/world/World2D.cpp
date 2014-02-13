/*
 * World2D.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "World2D.h"
#include <iostream>

using namespace std;

World2D::World2D()
{
	sizeX = 0;
	sizeY = 0;

	leftWorld = 0;
	rightWorld = 0;
	topWorld = 0;
	bottomWorld = 0;
}

World2D::World2D(float sizeX, float sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	leftWorld = sizeX/2.0f;
	rightWorld = -leftWorld;
	topWorld = sizeY/2.0f;
	bottomWorld = -topWorld;
}

World2D::~World2D()
{

}

World2D::World2D(const World2D& other)
{
	this->sizeX = other.sizeX;
	this->sizeY = other.sizeY;

	this->leftWorld = other.leftWorld;
	this->rightWorld = other.rightWorld;
	this->topWorld = other.topWorld;
	this->bottomWorld = other.bottomWorld;
}

World2D& World2D::operator=(const World2D& other)
{
	if(this != &other)
	{
		this->sizeX = other.sizeX;
		this->sizeY = other.sizeY;

		this->leftWorld = other.leftWorld;
		this->rightWorld = other.rightWorld;
		this-> topWorld = other.topWorld;
		this->bottomWorld = other.bottomWorld;
	}

	return *this;
}

void World2D::draw()
{
	float lineWidth = 3.0f;
	glLineWidth(lineWidth);

	glBegin(GL_LINES);

		glColor3f(0.0, 0.0, 1.0); //blue
		glVertex3f(rightWorld, topWorld, 0.0f);
		glVertex3f(leftWorld, topWorld, 0.0f);

		glColor3f(0.0, 0.0, 1.0); //blue
		glVertex3f(rightWorld, bottomWorld, 0.0f);
		glVertex3f(leftWorld, bottomWorld, 0.0f);

		glColor3f(0.0, 0.0, 1.0); //blue
		glVertex3f(leftWorld, bottomWorld, 0.0f);
		glVertex3f(leftWorld, topWorld, 0.0f);

		glColor3f(0.0, 0.0, 1.0); //blue
		glVertex3f(rightWorld, bottomWorld, 0.0f);
		glVertex3f(rightWorld, topWorld, 0.0f);

	glEnd();
}

bool World2D::isInside(float posX, float posY)
{
	if(posX > leftWorld || posX < rightWorld || posY > topWorld || posY < bottomWorld)
		return false;

	return true;
}

OutsideWorld World2D::getOutsidePosition(Player2D player)
{
	OutsideWorld outsideWorld;

	float posX = player.getCurPosX();
	float posY = player.getCurPosY();
	float posZ = player.getCurPosZ();
	float height = player.getHeight();
	float base = player.getBase();

	if(posX + height/2 > leftWorld)
		outsideWorld.setBeyondLeft();
	else if(posX - height/2 < rightWorld)
		outsideWorld.setBeyondRight();

	if(posY + height/2 > topWorld)
		outsideWorld.setBeyondTop();
	else if(posY - height/2 < bottomWorld)
		outsideWorld.setBeyondBottom();

	return outsideWorld;
}

/*OutsideWorld World2D::getOutsidePosition(AdvancedBullet* bullet)
{
	OutsideWorld outsideWorld;

	float posX = bullet->getPosX();
	float posY = bullet->getPosY();

	if(posX > leftWorld)
		outsideWorld.setBeyondLeft();
	else if(posX < rightWorld)
		outsideWorld.setBeyondRight();

	if(posY > topWorld)
		outsideWorld.setBeyondTop();
	else if(posY < bottomWorld)
		outsideWorld.setBeyondBottom();

	return outsideWorld;
}*/

float World2D::getSizeX()
{
	return sizeX;
}

float World2D::getSizeY()
{
	return sizeY;
}

float World2D::getLeftWorld()
{
	return leftWorld;
}
float World2D::getRightWorld()
{
	return rightWorld;
}
float World2D::getTopWorld()
{
	return topWorld;
}
float World2D::getBottomWorld()
{
	return bottomWorld;
}
