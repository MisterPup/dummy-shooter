/*
 * Bullet.cpp
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#include "Bullet.h"

Bullet::Bullet(float bodyDimY, float topWorld, float bottomWorld)
{
	this->bodyDimY = bodyDimY;
	shot = false;
	firstTime = true;

	oldShiftX = 0.0f;
	oldShiftY = 0.0f;
	oldShiftZ = 0.0f;
	oldGunRotation = 0.0f;

	this->topWorld = topWorld;
	this->bottomWorld = bottomWorld;

	bulletPos = 0.0f;
	bulletSpeed = 0.0f;
}

float Bullet::getBodyDimY()
{
	return bodyDimY;
}

bool Bullet::isShot()
{
	return shot;
}

void Bullet::shoot(float shiftX, float shiftY, float shiftZ, float gunRotation, float bulletSpeed)
{
	if(!shot) //if the bullet is not already running
	{
		this->oldShiftX = shiftX;
		this->oldShiftY = shiftY;
		this->oldShiftZ = shiftZ;
		this->oldGunRotation = gunRotation;
		bulletPos = 0.0f;
		this->bulletSpeed = bulletSpeed;
		shot = true;
	}
}

bool Bullet::isFirstTime()
{
	return firstTime;
}

//Draws the Bullet
bool Bullet::draw()
{
	if(!shot)
		return false;	

	float bodyPosX = 0.0f;
	float bodyPosY1 = 0.0f + bulletPos;
	float bodyPosY2 = bodyPosY1 + bodyDimY;
	float bodyPosZ = 0.0f;

	if(bodyPosY2*cos(fabs(2*M_PI*oldGunRotation/360)) >= (topWorld - bottomWorld)) //the player is in bottomWorld position (distance from top of the world is topWorld - bottomWorld)
	{
		shot = false;
		bulletPos = 0.0f;
		return false;
	}

	glPushMatrix();
		glTranslatef(oldShiftX, oldShiftY, oldShiftZ);
		glRotatef(oldGunRotation, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINES);
		glColor3f(0.0, 0.5, 0.5);
		glVertex3f(bodyPosX, bodyPosY1, bodyPosZ);
		glVertex3f(bodyPosX, bodyPosY2, bodyPosZ);
		glEnd();
	glPopMatrix();

	bulletPos += bulletSpeed;

	return true;
}

Bullet::~Bullet()
{

}

