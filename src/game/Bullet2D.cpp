/*
 * Bullet2D.cpp
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#include "Bullet2D.h"
#include "GL/glut.h"
#include "math.h"
#include <iostream>
using namespace std;

Bullet2D::Bullet2D(float bodyDimY, float shootPosX, float shootPosY, float shootPosZ, float shootRotation)
{
	this->bodyDimY = bodyDimY;
	bulletPos = 0;
	bulletSpeed = 0.25f;

	this->shootPosX = shootPosX;
	this->shootPosY = shootPosY;
	this->shootPosZ = shootPosZ;
	this->shootRotation = shootRotation;
}

Bullet2D::~Bullet2D()
{
}

float Bullet2D::getPosY()
{

	float bodyPosY1 = bulletPos;
	float bodyPosY2 = bodyPosY1 + bodyDimY;

	float radAngle = 2*M_PI*shootRotation/360;
	float bulletPosY = bodyPosY2*cos(fabs(radAngle)) + shootPosY;

	return bulletPosY;
}

float Bullet2D::getPosX()
{
	float bodyPosY1 = bulletPos;
	float bodyPosY2 = bodyPosY1 + bodyDimY;

	float radAngle = 2*M_PI*shootRotation/360;
	float bulletPosX = bodyPosY2*sin(-radAngle) + shootPosX; //minus for simplicity

	return bulletPosX;
}

void Bullet2D::draw()
{
	float bodyPosX = 0.0f;
	float bodyPosY1 = bulletPos;
	float bodyPosY2 = bodyPosY1 + bodyDimY;
	float bodyPosZ = 0.0f;

	glPushMatrix();
		glTranslatef(shootPosX, shootPosY, shootPosZ);
		glRotatef(shootRotation, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINES);
			glColor3f(0.0, 0.5, 0.5);
			glVertex3f(bodyPosX, bodyPosY1, bodyPosZ);
			glVertex3f(bodyPosX, bodyPosY2, bodyPosZ);
		glEnd();
	glPopMatrix();

	bulletPos += bulletSpeed;
}
