/*
 * mouse.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "mouse.h"
#include "globalVariables.h"

void handleMousePress(int button, int state, int x, int y)
{
	mainMenu->pressButton(button, state, x, y);
}

