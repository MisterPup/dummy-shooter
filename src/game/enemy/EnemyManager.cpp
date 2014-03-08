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

void EnemyManager::manage(Player2DSystem playerSystem, Bullet2DSystem bulletSystem)
{
	for(unsigned int i = 0; i < enemies.size(); i++)
	{
		IEnemy2D* enemy = enemies.at(i);
		bool hit = checkIfHit(enemy, bulletSystem);
		//TODO eliminare anche il proiettile
		if(hit)
		{
			enemies.erase(enemies.begin() + i);
			i--;
		}
	}

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

bool EnemyManager::checkIfHit(IEnemy2D* enemy, Bullet2DSystem bulletSystem)
{
	vector<Bullet2D> bullets = bulletSystem.getBullets();
	for(unsigned int i = 0; i < bullets.size(); i++)
	{
		Bullet2D curBullet = bullets.at(i);

		float bulletPosX = curBullet.getPosX();
		float bulletPosY = curBullet.getPosY();

		bool hit = enemy->getShape()->isInside(enemy->getPosX(), enemy->getPosY(), bulletPosX, bulletPosY);

		if(hit)
			return true;
	}
	return false;
}

//TODO simple stub. Al momento è ridondante
bool EnemyManager::checkIfNewMustCreated()
{
	if(enemies.size() < maxNumEnemies)
		return true;

	return false;
}

void EnemyManager::createEnemy()
{
	while(enemies.size() < maxNumEnemies)
	{
		int enemyType = (int)(rand()%2); //0 e 1

		IEnemy2D* enemy;
		/*if(enemyType == 0)
			enemy = new EnemyTriangle();
		else*/
			enemy = new EnemyCircle();

		enemies.push_back(enemy);

		choosePositionToCreate(enemy);
	}
}

//TODO simple stub
void EnemyManager::choosePositionToCreate(IEnemy2D* enemy)
{
	//enemy->setPosX(world.getRightWorld()/2.0f);
	//enemy->setPosY(world.getTopWorld()/2.0f);

	int rightWorld = (int)world.getRightWorld();
	int topWorld = (int)world.getTopWorld();

	int xCoord = rand()%rightWorld;
	int xSign = rand()%2;
	xCoord = (xSign == 0) ? xCoord : -xCoord;

	int yCoord = rand()%topWorld;
	int ySign = rand()%2;
	yCoord = (ySign == 0) ? yCoord : -yCoord;

	enemy->setPosX(xCoord);
	enemy->setPosY(yCoord);
}

//TODO move this code into enemy
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
	float arccosInDegree = acos(dotProduct/(modulesEnemy*modulesPlayer))*180/M_PI; //se giocatore và esattamente su nemico, rischio di divisione per zero

	if(newPlayerX > 0)
		arccosInDegree = 360 - arccosInDegree;

	float enemyDeg = enemy->getDegRotation();
	float diff = arccosInDegree - enemyDeg;

	if(abs(diff) > 4.0f) //se troppo piccola rispetto alla rotazione del cannone del nemico, prova a spostare in continuazione verso destra e sinistra
	{
		bool right = true;
		if(diff < 0)
		{
			if(abs(diff) > 180)
				enemy->rotate(right);
			else
				enemy->rotate(!right);
		}
		else
		{
			if(diff > 180)
				enemy->rotate(!right);
			else
				enemy->rotate(right);
		}
	}
	else //ora che ho sistemato la rotazione, posso avvicinarmi
	{
		//aggiusta direzione

		float x = enemy->getPosX() - player.getCurPosX();
		float y = enemy->getPosY() - player.getCurPosY();
		float euclideanDistance = sqrt(pow(x, 2) + pow(y, 2));
		float distanceFromPlayerToReach = enemy->getDistanceFromPlayerToReach();

		if(euclideanDistance > distanceFromPlayerToReach) //nemico lontano da giocatore
			enemy->move(true);
	}
}

void EnemyManager::draw(IEnemy2D* enemy)
{
	enemy->draw();
}
