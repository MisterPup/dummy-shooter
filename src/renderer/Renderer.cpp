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
	renderable = gui;
}

Renderer::~Renderer()
{
	delete instance;
	//gui e game vengono eliminati dai relativi distruttori, essendoci un solo oggetto singleton
}

Renderer* Renderer::getInstance()
{
	if(instance == 0)
		instance = new Renderer();

	return instance;
}

Gui* Renderer::getGui()
{
	return gui;
}

Game* Renderer::getGame()
{
	return game;
}

void Renderer::changeToGui()
{
	renderable = gui;
}
void Renderer::changeToGame()
{
	renderable = game;
}

void Renderer::changeToOther()
{
	if(renderable == gui)
		renderable = game;
	else
		renderable = gui;
}

void Renderer::exitGame()
{
	exit(0);
}

void Renderer::leftClick(float x, float y)
{
	renderable->leftClick(x, y);
}

void Renderer::pressStandardKey(int key)
{
	if(key == 27) //ESC - se sono in game, vado nel relativo menù
		changeToGui();
	else
		renderable->pressStandardKey(key);
}

void Renderer::pressSpecialKey(int key)
{
	renderable->pressSpecialKey(key);
}

void Renderer::draw()
{
	renderable->draw();
}
