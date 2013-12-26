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
	enemy->setPosX(world.getRightWorld()/2.0f);
	enemy->setPosY(world.getTopWorld()/2.0f);
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

	//aggiusta rotazione

	//sposto le coordinate nel centro del nemico
	float newPlayerX = player.getCurPosX() - enemy->getPosX();
	float newPlayerY = player.getCurPosY() - enemy->getPosY();
	//calcolo l'angolo fra i vettori [0, 1] e [newPlayerX, newPlayerY]
	float dotProduct = newPlayerY; //0*newPlayerX + 1*newPlayerY
	float modulesEnemy = 1; //sqrt(pow(0, 2) + pow(1, 2))
	float modulesPlayer = sqrt(pow(newPlayerX, 2) + pow(newPlayerY, 2));
	float arccosInDegree = acos(dotProduct/(modulesEnemy*modulesPlayer))*180/M_PI;

	float posEnemyDeg = enemy->getDegRotation() < 0 ? -enemy->getDegRotation() : enemy->getDegRotation();
	//cout << "arc " << arccosInDegree << endl;
	//cout << "deg " << posEnemyDeg << endl;

	float diff = abs(arccosInDegree - posEnemyDeg);
	//cout << diff << endl;

	if(diff > 3.0f)
	{
		float rightDiff;
		float leftDiff;

		if(enemy->getDegRotation() < 0)
		{
			rightDiff = abs(arccosInDegree - (posEnemyDeg - enemy->getRotateBy()));
			leftDiff = abs(arccosInDegree - (posEnemyDeg + enemy->getRotateBy()));
		}
		else if(enemy->getDegRotation() > 0)
		{
			cout << "c\n";
			rightDiff = abs(arccosInDegree - (posEnemyDeg + enemy->getRotateBy()));
			leftDiff = abs(arccosInDegree - (posEnemyDeg - enemy->getRotateBy()));
		}
		else //enemy->getDegRotation() == 0
		{
			if(newPlayerX > 0) //giocatore a sinistra, devo girare a sinistra
			{
				rightDiff = 1;
				leftDiff = 0;
			}
			else //giocatore a destra, devo girare a destra
			{
				rightDiff = 0;
				leftDiff = 1;
			}
		}

		if(rightDiff < leftDiff)
			enemy->rotate(true);
		else
			enemy->rotate(false);
	}
	/*else //ora che ho sistemato la rotazione, posso avvicinarmi
	{
		//aggiusta direzione

		float x = enemy->getPosX() - player.getCurPosX();
		float y = enemy->getPosY() - player.getCurPosY();
		float euclideanDistance = sqrt(pow(x, 2) + pow(y, 2));
		float distanceFromPlayerToReach = enemy->getDistanceFromPlayerToReach();

		if(euclideanDistance > distanceFromPlayerToReach) //nemico lontano da giocatore
			enemy->move(true);
	}*/
}

void EnemyManager::draw(IEnemy2D* enemy)
{
	enemy->draw();
}
