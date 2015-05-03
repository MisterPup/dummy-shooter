/*
 * Renderer.cpp
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#include "Renderer.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

Renderer* Renderer::instance = 0;

Renderer::Renderer()
{
	gui = Gui::getInstance();
	game = Game::getInstance();
	currentRendered = gui;
}

Renderer::~Renderer()
{
	delete instance;
	//gui and game objects are deleted by their destructors
}

Renderer* Renderer::getInstance()
{
	if(instance == 0)
		instance = new Renderer();

	return instance;
}

Gui* Renderer::getGui() const
{
	return gui;
}

Game* Renderer::getGame() const
{
	return game;
}

void Renderer::changeToGui()
{
	currentRendered = gui;
}
void Renderer::changeToGame()
{
	currentRendered = game;
}

void Renderer::changeToOther()
{
	if(currentRendered == gui)
		currentRendered = game;
	else
		currentRendered = gui;
}

void Renderer::exitGame()
{
	exit(0);
}

void Renderer::leftClick(float x, float y)
{
	currentRendered->leftClick(x, y);
}

void Renderer::pressStandardKey(int key)
{
	if(key == 27) //ESC - if in game, go to menu
		changeToGui();
	else
		currentRendered->pressStandardKey(key);
}

void Renderer::pressSpecialKey(int key)
{
	currentRendered->pressSpecialKey(key);
}

void Renderer::draw()
{
	currentRendered->draw();
}

void Renderer::setUpdateTime(float updateTime) {
	IDrawable::updateTime = updateTime;
}
