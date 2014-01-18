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
	//float distanceFromPlayerToReach = 3.0f;
	//setDistanceFromPlayerToReach(distanceFromPlayerToReach);
}

EnemyCircle::~EnemyCircle()
{

}

void EnemyCircle::draw()
{
	glPushMatrix();
		glTranslatef(getPosX(), getPosY(), getPosZ());
		glRotatef(getDegRotation(), 0.0f, 0.0f, 1.0f);

		bool filled = true;
		Circle circle(radius, numSegments, filled);
		circle.draw();
	glPopMatrix();
}
