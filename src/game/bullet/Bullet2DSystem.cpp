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
}

Bullet2DSystem::Bullet2DSystem(const World2D& world, int numBullets, float bulletDimY)
{
	this->world = world;
	this->numBullets = numBullets;
	this->bulletDimY = bulletDimY;
}

Bullet2DSystem& Bullet2DSystem::operator=(const Bullet2DSystem& other)
{
	world = other.world;
	numBullets = other.numBullets;
	bulletDimY = other.bulletDimY;

	return *this;
}

Bullet2DSystem::~Bullet2DSystem()
{
}

void Bullet2DSystem::shoot(Player2D player)
{
	if(bullets.size() >= numBullets)
		return;

	Bullet2D bullet(bulletDimY,
					player.getCurPosX(), player.getCurPosY(), player.getCurPosZ(),
					player.getDegRotation());
	bullets.push_back(bullet);
}

void Bullet2DSystem::draw()
{
	for(int i = bullets.size() - 1; i >= 0; i--)
	{
		Bullet2D* bullet = &bullets.at(i);

		//draw only if the bullet is still inside the world
		if(checkInsideWorld(*bullet, i))
			bullet->draw();
		else
			destroyBullet(i);
	}
}

void Bullet2DSystem::destroyBullet(int index)
{
	bullets.erase(bullets.begin() + index);
}

bool Bullet2DSystem::checkInsideWorld(const Bullet2D& bullet, int indexInBullets)
{
	return world.isInside(bullet.getPosX(), bullet.getPosY());
}

const vector<Bullet2D>& Bullet2DSystem::getBullets() const
{
	return bullets;
}
