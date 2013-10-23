/*
 * AdvancedPlayer.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "AdvancedPlayer.h"
#include <GL/glut.h>
#include <math.h>

AdvancedPlayer::AdvancedPlayer(float base, float height)
{
	this->base = base;
	this->height = height;

	degRotation = 0.0f;

	curPosX = 0.0f;
	curPosY = 0.0f;
	curPosZ = 0.0f;

	moveBy = 0.15f;
	rotateBy = 10.0f;

	teleport = true;
}

AdvancedPlayer::~AdvancedPlayer()
{

}

void AdvancedPlayer::move(bool forward)
{
	float radRotation = 2*M_PI*degRotation/360; //rotation in radiants

	//radRotation is negative when you press LEFT
	float toMoveX = moveBy*cos(M_PI/2 + radRotation);
	float toMoveY = moveBy*sin(M_PI/2 + radRotation);

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

void AdvancedPlayer::rotate(bool right)
{
	if(right)
		degRotation += rotateBy;
	else
		degRotation -= rotateBy;
}

void AdvancedPlayer::draw()
{
	glPushMatrix();
		glTranslatef(curPosX, curPosY, curPosZ);
		glRotatef(degRotation, 0.0f, 0.0f, 1.0f);

		drawTriangle();
	glPopMatrix();
}

void AdvancedPlayer::drawTriangle()
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

float AdvancedPlayer::getBase()
{
	return base;
}

float AdvancedPlayer::getHeight()
{
	return height;
}

float AdvancedPlayer::getCurPosX()
{
	return curPosX;
}

float AdvancedPlayer::getCurPosY()
{
	return curPosY;
}

float AdvancedPlayer::getCurPosZ()
{
	return curPosZ;
}

float AdvancedPlayer::getDegRotation()
{
	return degRotation;
}

float AdvancedPlayer::getMoveBy()
{
	return moveBy;
}

float AdvancedPlayer::getRotateBy()
{
	return rotateBy;
}

bool AdvancedPlayer::getTeleport()
{
	return teleport;
}

void AdvancedPlayer::setCurPosX(float curPosX)
{
	this->curPosX = curPosX;
}
void AdvancedPlayer::setCurPosY(float curPosY)
{
	this->curPosY = curPosY;
}
void AdvancedPlayer::setCurPosZ(float curPosZ)
{
	this->curPosZ = curPosZ;
}

void AdvancedPlayer::setDegRotation(float degRotation)
{
	this->degRotation = degRotation;
}

void AdvancedPlayer::setTeleport(bool teleport)
{
	this->teleport = teleport;
}
