/*
 * Player2DSystem.cpp
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#include "Player2DSystem.h"
#include "../world/OutsideWorld.h"

Player2DSystem::Player2DSystem()
{

}

Player2DSystem::Player2DSystem(World2D world)
{
	this->world = world;

	float base = 0.5f;
	float height = 0.5f;

	Player2D tempPlayer(base, height);
	player = tempPlayer;
}

Player2DSystem::Player2DSystem(World2D world, Player2D player)
{
	this->world = world;
	this->player = player;
}

Player2DSystem& Player2DSystem::operator=(const Player2DSystem& other)
{
	world = other.world;
	player = other.player;

	return *this;
}

Player2DSystem::~Player2DSystem()
{

}

Player2D Player2DSystem::getPlayer()
{
	return player;
}

void Player2DSystem::draw()
{
	player.draw();
}

void Player2DSystem::rotate(bool right)
{
	player.rotate(right);
}

void Player2DSystem::move(bool forward)
{
	player.move(forward);

	if(forward)
		moveForward();
	else
		moveBackward();
}

void Player2DSystem::moveForward()
{
	float sizeX = world.getSizeX();
	float sizeY = world.getSizeY();

	float height = player.getHeight();
	float base = player.getBase();

	float newPosX = player.getCurPosX();
	float newPosY = player.getCurPosY();

	if(player.getTeleport())
	{
		OutsideWorld outsideWorld = world.getOutsidePosition(player);

		if(outsideWorld.isBeyondLeft())
			newPosX -= sizeX - height; //equals to newPosX = newPosx - (sizeX - height/2)
		else if(outsideWorld.isBeyondRight())
			newPosX += sizeX - height;

		if(outsideWorld.isBeyondTop())
			newPosY -= sizeY - height;
		else if(outsideWorld.isBeyondBottom())
			newPosY += sizeY - height;

		player.setCurPosX(newPosX);
		player.setCurPosY(newPosY);
	}
	else
	{
		if(!world.isInside(newPosX, newPosY))
		{
			player.move(false);
		}
	}
}

void Player2DSystem::moveBackward()
{
	float sizeX = world.getSizeX();
	float sizeY = world.getSizeY();

	float height = player.getHeight();
	float base = player.getBase();

	float newPosX = player.getCurPosX();
	float newPosY = player.getCurPosY();

	if(player.getTeleport())
	{
		OutsideWorld outsideWorld = world.getOutsidePosition(player);

		if(outsideWorld.isBeyondLeft())
			newPosX -= sizeX - height; //equals to newPosX = newPosx - (sizeX - height/2)
		else if(outsideWorld.isBeyondRight())
			newPosX += sizeX - height;

		if(outsideWorld.isBeyondTop())
			newPosY -= sizeY - height;
		else if(outsideWorld.isBeyondBottom())
			newPosY += sizeY - height;

		player.setCurPosX(newPosX);
		player.setCurPosY(newPosY);
	}
	else
	{
		if(!world.isInside(newPosX, newPosY))
		{
			player.move(true);
		}
	}
}
