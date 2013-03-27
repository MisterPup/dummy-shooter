/*
 * BulletSystem.cpp
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#include "BulletSystem.h"

BulletSystem::BulletSystem(int numBullets, float bodyDimY, float endY)
{
	this->numBullets = numBullets;
	this->bulletDimY = bodyDimY;
	index = 0;

	for(int i = 0; i < numBullets; i++)
	{
		Bullet newBullet(bulletDimY, endY);
		bullets.push_back(newBullet);
	}
}

void BulletSystem::fire(float shiftX, float shiftY, float shiftZ, float gunRotation, float bulletSpeed)
{
	bullets.at(index).shoot(shiftX, shiftY, shiftZ, gunRotation, bulletSpeed);
	index = (index + 1)%numBullets;
}

void BulletSystem::draw()
{
	for(int i = 0; i < numBullets; i++)
	{
		bullets.at(i).draw();
	}
}

BulletSystem::~BulletSystem()
{

}

