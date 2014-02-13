/*
 * SPActionListener.cpp
 *
 *  Created on: 21/nov/2013
 *      Author: misterpup
 */

#include "SPActionListener.h"
#include "../../renderer/Renderer.h"
#include <iostream>

using namespace std;

SPActionListener::SPActionListener()
{

}

SPActionListener::SPActionListener(SPActionListener const &)
{
}

SPActionListener::~SPActionListener()
{
}

void SPActionListener::actionPerformed()
{
	Renderer::getInstance()->changeToGame();
	Renderer::getInstance()->getGame()->initSinglePlayerGame();
	Renderer::getInstance()->getGui()->changeToSPMenu(); //Quando il giocatore preme ESC in game, compare il menu SP
}

ActionListener* SPActionListener::create() const
{
	return new SPActionListener();
}

ActionListener* SPActionListener::clone() const
{
	return new SPActionListener(*this);
}

