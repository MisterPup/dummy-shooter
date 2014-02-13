/*
 * BulletSystem.cpp
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#include "Bullet2DSystem.h"
#include "../player/Player2D.h"
#include <iostream>

using namespace std;

Bullet2DSystem::Bullet2DSystem()
{
	numBullets = 5;
	bulletDimY = 0.1f;
	bulletsShoot = 0;
}

Bullet2DSystem::Bullet2DSystem(World2D world, int numBullets, float bulletDimY)
{
	this->world = world;
	this->numBullets = numBullets;
	this->bulletDimY = bulletDimY;
	bulletsShoot = 0;
}

Bullet2DSystem& Bullet2DSystem::operator=(const Bullet2DSystem& other)
{
	world = other.world;
	numBullets = other.numBullets;
	bulletDimY = other.bulletDimY;
	bulletsShoot = other.bulletsShoot;

	return *this;
}

Bullet2DSystem::~Bullet2DSystem()
{
}

void Bullet2DSystem::shoot(Player2D player)
{
	if(bulletsShoot >= numBullets)
		return;

	Bullet2D bullet(bulletDimY, player.getCurPosX(), player.getCurPosY(), player.getCurPosZ(), player.getDegRotation());
	bullets.push_back(bullet);
	bulletsShoot++;
}

void Bullet2DSystem::draw()
{
	for(int i = 0; i < bulletsShoot; i++)
	{
		Bullet2D* bullet = &bullets.at(i); //necessario che sia un puntatore, altrimenti manipolo un altro oggetto e il proiettile non si muove!

		if(checkInsideWorld(*bullet, i))
			bullet->draw();
		else
			i--;
	}
}

bool Bullet2DSystem::checkInsideWorld(Bullet2D bullet, int indexInBullets)
{
	if(!world.isInside(bullet.getPosX(), bullet.getPosY()))
	{
		bullets.erase(bullets.begin() + indexInBullets);
		bulletsShoot--;
		return false;
	}

	return true;
}

const vector<Bullet2D>& Bullet2DSystem::getBullets() const
{
	return bullets;
}
