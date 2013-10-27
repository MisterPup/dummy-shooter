/*
 * Player2D.cpp
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#include "Player2D.h"

Player2D::Player2D(float bodyDimX, float bodyDimY, float gunDimX, float gunDimY)
{
	this->bodyDimX = bodyDimX;
	this->bodyDimY = bodyDimY;
	this->gunDimX = gunDimX;
	this->gunDimY = gunDimY;
}

float Player2D::getBodyDimX()
{
	return bodyDimX;
}

float Player2D::getBodyDimY()
{
	return bodyDimY;
}

float Player2D::getGunDimX()
{
	return gunDimX;
}

float Player2D::getGunDimY()
{
	return gunDimY;
}

//Draws Body and Gun
void Player2D::draw(float gun_rotation)
{
	//Body
	float halfBodyDimX = bodyDimX/2;
	float halfBodyDimY = bodyDimY/2;
	float bodyPosZ = 0.0f;

	glBegin(GL_QUADS);
	glVertex3f(-halfBodyDimX, -halfBodyDimY, bodyPosZ);
	glVertex3f(halfBodyDimX, -halfBodyDimY, bodyPosZ);
	glVertex3f(halfBodyDimX, halfBodyDimY, bodyPosZ);
	glVertex3f(-halfBodyDimX, halfBodyDimY, bodyPosZ);
	glEnd();

	//Gun
	glPushMatrix();
		float halfGunDimX = gunDimX/2;
		float halfGunDimY = gunDimY/2;
		float gunPosZ = 0.0f;

		glTranslatef(0.0, halfBodyDimY, 0.0f); //top of the body
		glRotatef(gun_rotation, 0.0f, 0.0f, 1.0f);

		glBegin(GL_QUADS);
		glVertex3f(-halfGunDimX, -halfGunDimY, gunPosZ);
		glVertex3f(halfGunDimX, -halfGunDimY, gunPosZ);
		glVertex3f(halfGunDimX, halfGunDimY, gunPosZ);
		glVertex3f(-halfGunDimX, halfGunDimY, gunPosZ);
		glEnd();
	glPopMatrix();
}

Player2D::~Player2D()
{

}

