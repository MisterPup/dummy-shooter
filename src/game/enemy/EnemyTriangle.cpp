/*
 * EnemyTriangle.cpp
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#include "EnemyTriangle.h"
#include "../shape/Triangle.h"
#include <GL/glut.h>
#include <math.h>

EnemyTriangle::EnemyTriangle():IEnemy2D()
{
	moveBy = 0.05f;
	rotateBy = 5.0f;

	setMoveBy(moveBy);
	setRotateBy(rotateBy);

	distanceFromPlayerToReach = 2.0f;
}

EnemyTriangle::~EnemyTriangle()
{

}

void EnemyTriangle::draw()
{
	glPushMatrix();
		glTranslatef(getPosX(), getPosY(), getPosZ());
		glRotatef(getDegRotation(), 0.0f, 0.0f, 1.0f);

		float base = 0.5f;
		float height = 0.5f;
		Triangle triangle(base, height);
		triangle.draw();
	glPopMatrix();
}

float EnemyTriangle::getDistanceFromPlayerToReach() const
{
	return distanceFromPlayerToReach;
}

void EnemyTriangle::setDistanceFromPlayerToReach(float distanceFromPlayerToReach)
{
	this->distanceFromPlayerToReach = distanceFromPlayerToReach;
}
