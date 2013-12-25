/*
 * EnemyManager.cpp
 *
 *  Created on: 25/dic/2013
 *      Author: misterpup
 */

#include "EnemyManager.h"
#include "EnemyTriangle.h"
#include "EnemyCircle.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

EnemyManager::EnemyManager()
{
	init();
}

EnemyManager::EnemyManager(World2D world)
{
	this->world = world;
	init();
}

EnemyManager::~EnemyManager()
{
}

EnemyManager::EnemyManager(const EnemyManager& other)
{
	init();
	this->world = other.world;
	maxNumEnemies = other.maxNumEnemies;
}

EnemyManager& EnemyManager::operator =(const EnemyManager& other)
{
	init();
	this->world = other.world;
	maxNumEnemies = other.maxNumEnemies;

	return *this;
}

void EnemyManager::init()
{
	maxNumEnemies = 1;
	srand(time(NULL));
}

void EnemyManager::manage(Player2DSystem playerSystem)
{
	bool mustCreate = checkIfNewMustCreated();
	if(mustCreate)
		createEnemy();

	for(unsigned int i = 0; i < enemies.size(); i++)
	{
		IEnemy2D* enemy = enemies.at(i);
		changeAndMoveTowardObjective(enemy, playerSystem);
		enemy->draw();
	}
}

bool EnemyManager::checkIfNewMustCreated()
{
	if(enemies.size() < maxNumEnemies)
		return true;

	return false;
}

void EnemyManager::createEnemy()
{
	//rand() per scegliere fra tipi di nemici da creare
	IEnemy2D* enemy = new EnemyTriangle();
	enemies.push_back(enemy);

	choosePositionToCreate(enemy);
}

void EnemyManager::choosePositionToCreate(IEnemy2D* enemy)
{
	enemy->setPosX(world.getRightWorld());
	enemy->setPosY(world.getTopWorld());
	/*float boundaries[4] = {world.getTopWorld(), world.getBottomWorld(), world.getRightWorld(), world.getLeftWorld()};
	int randomBoundary = rand()%4;

	if(randomBoundary == 0 || randomBoundary == 1)
	{
		int length = abs(boundaries[2] - boundaries[3]);

	}
	else if(randomBoundary == 2 || randomBoundary == 3)
	{
		int length = abs(boundaries[0] - boundaries[1]);

	}*/
}

void EnemyManager::changeAndMoveTowardObjective(IEnemy2D* enemy, Player2DSystem playerSystem)
{
	Player2D player = playerSystem.getPlayer();
	float x = enemy->getPosX() - player.getCurPosX();
	float y = enemy->getPosY() - player.getCurPosY();
	float euclideanDistance = sqrt(pow(x, 2) + pow(y, 2));

	float distanceFromPlayerToReach = enemy->getDistanceFromPlayerToReach();
	if(euclideanDistance > distanceFromPlayerToReach) //nemico lontano da giocatore
	{
		float dotProduct = enemy->getPosX()*player.getCurPosX() + enemy->getPosY()*player.getCurPosY();
		float modulesEnemy = sqrt(pow(enemy->getPosX(), 2) + pow(enemy->getPosY(), 2));
		float modulesPlayer = sqrt(pow(player.getCurPosX(), 2) + pow(player.getCurPosY(), 2));
		float arccosInDegree = acos(dotProduct/(modulesEnemy*modulesPlayer))*180/M_PI;

		if(abs(arccosInDegree - enemy->getDegRotation()) > 10.0f) //TODO per prova
			enemy->rotate(false);

		cout << arccosInDegree << endl;
		//playerSystem.move(true);
		//playerSystem.rotate(true);
		//if(y > 0) //
	}
}

void EnemyManager::draw(IEnemy2D* enemy)
{
	enemy->draw();
}
