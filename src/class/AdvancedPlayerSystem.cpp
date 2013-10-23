/*
 * AdvancedPlayerSystem.cpp
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#include "AdvancedPlayerSystem.h"
#include "OutsideWorld.h"

AdvancedPlayerSystem::AdvancedPlayerSystem(World2D* world, AdvancedPlayer* player)
{
	this->world = world;
	this->player = player;
}

AdvancedPlayerSystem::~AdvancedPlayerSystem()
{

}

void AdvancedPlayerSystem::draw()
{
	player->draw();
}

void AdvancedPlayerSystem::rotate(bool right)
{
	player->rotate(right);
}

void AdvancedPlayerSystem::move(bool forward)
{
	player->move(forward);

	if(forward)
		moveForward();
	else
		moveBackward();
}

void AdvancedPlayerSystem::moveForward()
{
	float sizeX = world->getSizeX();
	float sizeY = world->getSizeY();

	float height = player->getHeight();
	float base = player->getBase();

	float newPosX = player->getCurPosX();
	float newPosY = player->getCurPosY();

	if(player->getTeleport())
	{
		OutsideWorld outsideWorld = world->getOutsidePosition(player);

		if(outsideWorld.isBeyondLeft())
			newPosX -= sizeX - height; //equals to newPosX = newPosx - (sizeX - height/2)
		else if(outsideWorld.isBeyondRight())
			newPosX += sizeX - height;

		if(outsideWorld.isBeyondTop())
			newPosY -= sizeY - height;
		else if(outsideWorld.isBeyondBottom())
			newPosY += sizeY - height;

		player->setCurPosX(newPosX);
		player->setCurPosY(newPosY);
	}
	else
	{
		if(!world->isInside(newPosX, newPosY))
		{
			player->move(false);
		}
	}
}

void AdvancedPlayerSystem::moveBackward()
{
	float sizeX = world->getSizeX();
	float sizeY = world->getSizeY();

	float height = player->getHeight();
	float base = player->getBase();

	float newPosX = player->getCurPosX();
	float newPosY = player->getCurPosY();

	if(player->getTeleport())
	{
		OutsideWorld outsideWorld = world->getOutsidePosition(player);

		if(outsideWorld.isBeyondLeft())
			newPosX -= sizeX - height; //equals to newPosX = newPosx - (sizeX - height/2)
		else if(outsideWorld.isBeyondRight())
			newPosX += sizeX - height;

		if(outsideWorld.isBeyondTop())
			newPosY -= sizeY - height;
		else if(outsideWorld.isBeyondBottom())
			newPosY += sizeY - height;

		player->setCurPosX(newPosX);
		player->setCurPosY(newPosY);
	}
	else
	{
		if(!world->isInside(newPosX, newPosY))
		{
			player->move(true);
		}
	}
}
