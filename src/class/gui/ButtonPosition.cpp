/*
 * ButtonPosition.cpp
 *
 *  Created on: 26/ott/2013
 *      Author: misterpup
 */

#include "ButtonPosition.h"

ButtonPosition::ButtonPosition(float position[2], Button button)
{
	posX = position[0];
	posY = position[1];
	this->button = new Button(button);
}

ButtonPosition::~ButtonPosition()
{
}

