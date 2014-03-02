/*
 * IEnemyAI.cpp
 *
 *  Created on: 01/mar/2014
 *      Author: misterpup
 */

#include "IEnemyAI.h"

IEnemyAI::IEnemyAI(World2D world, IEnemy2D* enemy, Player2DSystem playerSystem)
{
	this->world = world;
	this->playerSystem = playerSystem;
}

Player2DSystem IEnemyAI::getPlayerSystem() const
{
	return playerSystem;
}

void IEnemyAI::setPlayerSystem(Player2DSystem& playerSystem)
{
	this->playerSystem = playerSystem;
}

World2D IEnemyAI::getWorld() const
{
	return world;
}

void IEnemyAI::setWorld(World2D& world)
{
	this->world = world;
}

IEnemyAI::~IEnemyAI()
{
}

