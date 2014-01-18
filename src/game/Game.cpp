/*
 * Game.cpp
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#include "Game.h"
#include "enemy/EnemyTriangle.h"
#include "enemy/EnemyCircle.h"
#include <iostream>

using namespace std;

Game* Game::instance = 0;

Game::Game()
{
	initObject();

	singlePlayer = true;
}

Game::~Game()
{
	delete instance;
}

Game* Game::getInstance()
{
	if(instance == 0)
		instance = new Game();

	return instance;
}

void Game::initObject()
{
	const float worldSizeX = 10.0f;
	const float worldSizeY = 8.0f;

	World2D tempWorld(worldSizeX, worldSizeY);
	world = tempWorld;

	//-------------------------------------------------------//

	Player2DSystem tempPlayerSystem(world);
	playerSystem = tempPlayerSystem;

	//-------------------------------------------------------//

	float bulletDimY = 0.1f;
	int numBullets = 5;

	Bullet2DSystem tempBulletSystem(world, numBullets, bulletDimY);
	bulletSystem = tempBulletSystem;

	//-------------------------------------------------------//

	EnemyManager tempEnemyManager(world);
	enemyManager = tempEnemyManager;
}

void Game::initSinglePlayerGame()
{
	singlePlayer = true;
}

bool Game::initMultiPlayerGame()
{
	singlePlayer = false;

	//client.connect();
	//return client.isConnected();

	return false;
}

void Game::resetGame()
{
	if(singlePlayer)
		resetSinglePlayerGame();
	else
		resetMultiPlayerGame();
}

void Game::resetSinglePlayerGame()
{
	initObject();
}

void Game::resetMultiPlayerGame()
{
	//client.disconnect();
}

World2D Game::getWorld()
{
	return world;
}

Player2DSystem Game::getPlayerSystem()
{
	return playerSystem;
}

Bullet2DSystem Game::getBulletSystem()
{
	return bulletSystem;
}

void Game::leftClick(float x, float y)
{

}

void Game::pressStandardKey(int key)
{
	if(key == 'w') //119
	{
		playerSystem.move(true);
	}
	else if(key == 's') //115
	{
		playerSystem.move(false);
	}
	else if(key == 'a') //97
	{
	}
	else if(key == 'd') //100
	{
	}
	else if(key == 32) //space
	{
		bulletSystem.shoot(playerSystem.getPlayer());
	}
}

void Game::pressSpecialKey(int key)
{
	if(key == GLUT_KEY_RIGHT)
		playerSystem.rotate(true);
	if(key == GLUT_KEY_LEFT)
		playerSystem.rotate(false);
}

void Game::draw()
{
	if(singlePlayer)
		drawSinglePlayer();
	else
		drawMultiPlayer();
}

void Game::drawSinglePlayer()
{
	world.draw();
	playerSystem.draw();
	bulletSystem.draw();
	enemyManager.manage(playerSystem, bulletSystem);
}

void Game::drawMultiPlayer()
{

}

