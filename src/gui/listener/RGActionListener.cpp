/*
 * RGActionListener.cpp
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#include "RGActionListener.h"
#include "../../renderer/Renderer.h"

RGActionListener::RGActionListener()
{

}

RGActionListener::RGActionListener(RGActionListener const &)
{
}

RGActionListener::~RGActionListener()
{
}

void RGActionListener::actionPerformed()
{
	Renderer::getInstance()->changeToGame();
}

ActionListener* RGActionListener::create() const
{
	return new RGActionListener();
}

ActionListener* RGActionListener::clone() const
{
	return new RGActionListener(*this);
}

