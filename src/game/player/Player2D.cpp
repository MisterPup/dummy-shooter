/*
 * Player2D.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "Player2D.h"
#include <GL/glut.h>
#include <math.h>

float Player2D::MOVEBY = 7.0f;
float Player2D::ROTATEBY = 10.0f;
float Player2D::BASE = 0.5f;
float Player2D::HEIGHT = 0.5f;

Player2D::Player2D()
{
	base = BASE;
	height = HEIGHT;

	degRotation = 0.0f;

	curPosX = 0.0f;
	curPosY = 0.0f;
	curPosZ = 0.0f;

	moveBy = MOVEBY;
	rotateBy = ROTATEBY;

	teleport = true;
}

Player2D& Player2D::operator=(const Player2D& other)
{
	base = other.base;
	height = other.height;

	degRotation = other.degRotation;

	curPosX = other.curPosX;
	curPosY = other.curPosY;
	curPosZ = other.curPosZ;

	moveBy = other.moveBy;
	rotateBy = other.rotateBy;

	teleport = other.teleport;

	return *this;
}

Player2D::~Player2D()
{

}

Player2D::Player2D(const Player2D& other)
{
	this->base = other.base;
	this->height = other.height;

	degRotation = other.degRotation;

	curPosX = other.curPosX;
	curPosY = other.curPosY;
	curPosZ = other.curPosZ;

	moveBy = other.moveBy;
	rotateBy = other.rotateBy;

	teleport = other.teleport;
}

void Player2D::move(bool forward)
{
	float updateTime = IDrawable::updateTime;
	float radRotation = 2*M_PI*degRotation/360; //rotation in radiants

	//radRotation is negative when you press LEFT
	float toMoveX = moveBy*updateTime*cos(M_PI/2 + radRotation);
	float toMoveY = moveBy*updateTime*sin(M_PI/2 + radRotation);

	if(forward)
	{
		curPosX += toMoveX;
		curPosY += toMoveY;
	}
	else
	{
		curPosX -= toMoveX;
		curPosY -= toMoveY;
	}
}

void Player2D::rotate(bool right)
{
	if(right)
		degRotation += rotateBy;
	else
		degRotation -= rotateBy;

	if(degRotation > 360)
		degRotation -= 360;

	if(degRotation < -360)
		degRotation += 360;
}

void Player2D::draw()
{
	glPushMatrix();
		glTranslatef(curPosX, curPosY, curPosZ);
		glRotatef(degRotation, 0.0f, 0.0f, 1.0f);

		drawTriangle();
	glPopMatrix();
}

void Player2D::drawTriangle()
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

float Player2D::getBase() const
{
	return base;
}

float Player2D::getHeight() const
{
	return height;
}

float Player2D::getCurPosX() const
{
	return curPosX;
}

float Player2D::getCurPosY() const
{
	return curPosY;
}

float Player2D::getCurPosZ() const
{
	return curPosZ;
}

float Player2D::getDegRotation() const
{
	return degRotation;
}

float Player2D::getMoveBy() const
{
	return moveBy;
}

float Player2D::getRotateBy() const
{
	return rotateBy;
}

bool Player2D::getTeleport() const
{
	return teleport;
}

void Player2D::setCurPosX(float curPosX)
{
	this->curPosX = curPosX;
}
void Player2D::setCurPosY(float curPosY)
{
	this->curPosY = curPosY;
}
void Player2D::setCurPosZ(float curPosZ)
{
	this->curPosZ = curPosZ;
}

void Player2D::setDegRotation(float degRotation)
{
	this->degRotation = degRotation;
}

void Player2D::setTeleport(bool teleport)
{
	this->teleport = teleport;
}
