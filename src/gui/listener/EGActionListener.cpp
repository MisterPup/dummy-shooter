/*
 * EGActionListener.cpp
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#include "EGActionListener.h"
#include "../../Renderer.h"

EGActionListener::EGActionListener()
{

}

EGActionListener::EGActionListener(EGActionListener const &)
{
}

EGActionListener::~EGActionListener()
{
}

void EGActionListener::actionPerformed()
{
	Renderer::getInstance()->exitGame();
}

ActionListener* EGActionListener::create() const
{
	return new EGActionListener();
}

ActionListener* EGActionListener::clone() const
{
	return new EGActionListener(*this);
}

