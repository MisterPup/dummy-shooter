/*
 * EnemyTriangle.cpp
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#include "EnemyTriangle.h"
#include <GL/glut.h>
#include <math.h>

EnemyTriangle::EnemyTriangle():IEnemy2D()
{
	float base = 0.5f;
	float height = 0.5f;
	Triangle triangle(base, height);
	setShape(&triangle);
	//float moveBy = 0.05;
	//float rotateBy = 5.0f;
	//float distanceFromPlayerToReach = 2.0f;

	//setMoveBy(moveBy);
	//setRotateBy(rotateBy);
	//setDistanceFromPlayerToReach(distanceFromPlayerToReach);
}

EnemyTriangle::~EnemyTriangle()
{

}

void EnemyTriangle::draw()
{
	glPushMatrix();
		glTranslatef(getPosX(), getPosY(), getPosZ());
		glRotatef(getDegRotation(), 0.0f, 0.0f, 1.0f);
		getShape()->draw();
	glPopMatrix();
}
