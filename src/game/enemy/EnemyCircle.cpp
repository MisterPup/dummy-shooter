/*
 * EnemyCircle.cpp
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#include "EnemyCircle.h"
#include "../shape/Circle.h"
#include <GL/glut.h>

EnemyCircle::EnemyCircle()
{
	distanceFromPlayerToReach = 3.0f;
}

EnemyCircle::~EnemyCircle()
{

}

void EnemyCircle::draw()
{
	glPushMatrix();
		glTranslatef(getPosX(), getPosY(), getPosZ());
		glRotatef(getDegRotation(), 0.0f, 0.0f, 1.0f);

		float radius = 0.2;
		int numSegments = 100;
		bool filled = true;
		Circle circle(radius, numSegments, filled);
		circle.draw();
	glPopMatrix();
}

float EnemyCircle::getDistanceFromPlayerToReach() const
{
	return distanceFromPlayerToReach;
}

void EnemyCircle::setDistanceFromPlayerToReach(float distanceFromPlayerToReach)
{
	this->distanceFromPlayerToReach = distanceFromPlayerToReach;
}
