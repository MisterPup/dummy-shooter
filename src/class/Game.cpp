/*
 * Game.cpp
 *
 *  Created on: 27/ott/2013
 *      Author: misterpup
 */

#include "Game.h"

Game::Game()
{
	createStates();
}

void Game::createStates()
{
	State a("");
	State b("");
	State c("");
	State d("");
	states.push_back(a);
	states.push_back(b);
	states.push_back(c);
	states.push_back(d);
}

Game::~Game()
{

}

