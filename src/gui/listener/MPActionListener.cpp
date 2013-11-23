/*
 * MPActionListener.cpp
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#include "MPActionListener.h"
#include "../../Renderer.h"

MPActionListener::MPActionListener()
{

}

MPActionListener::MPActionListener(MPActionListener const &)
{
}

MPActionListener::~MPActionListener()
{
}

void MPActionListener::actionPerformed()
{
	Renderer::getInstance()->getGui()->changeToMPNotConnectedMenu();
}

ActionListener* MPActionListener::create() const
{
	return new MPActionListener();
}

ActionListener* MPActionListener::clone() const
{
	return new MPActionListener(*this);
}
