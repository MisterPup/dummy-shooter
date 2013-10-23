/*
 * AdvancedBulletSystem.cpp
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#include "AdvancedBulletSystem.h"
#include "AdvancedPlayer.h"
#include <iostream>

using namespace std;

AdvancedBulletSystem::AdvancedBulletSystem(World2D* world, int numBullets, float bulletDimY)
{
	this->world = world;
	this->numBullets = numBullets;
	this->bulletDimY = bulletDimY;
	bulletsShoot = 0;

	vector<AdvancedBullet> bullets;
}

AdvancedBulletSystem::~AdvancedBulletSystem()
{
}

void AdvancedBulletSystem::shoot(AdvancedPlayer* player)
{
	if(bulletsShoot >= numBullets)
		return;

	AdvancedBullet bullet(bulletDimY, player->getCurPosX(), player->getCurPosY(), player->getCurPosZ(), player->getDegRotation());
	bullets.push_back(bullet);
	bulletsShoot++;
}

void AdvancedBulletSystem::draw()
{
	for(int i = 0; i < bulletsShoot; i++)
	{
		AdvancedBullet* bullet = &bullets.at(i);

		if(checkInsideWorld(bullet, i))
			bullet->draw();
		else
			i--;
	}
}

bool AdvancedBulletSystem::checkInsideWorld(AdvancedBullet* bullet, int indexInBullets)
{
	if(!world->isInside(bullet->getPosX(), bullet->getPosY()))
	{
		bullets.erase(bullets.begin() + indexInBullets);
		bulletsShoot--;
		return false;
	}

	return true;
}
