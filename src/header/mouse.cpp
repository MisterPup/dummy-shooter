/*
 * mouse.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "mouse.h"
#include "globalVariables.h"
#include "utils.h"
#include <iostream>

using namespace std;

void handleMousePress(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		if(state == GLUT_UP)
		{
			GLfloat screenCoordinates[2];
			int numScreenCoordinates = 2;

			screenCoordinates[0] = x;
			screenCoordinates[1] = y;

			GLdouble worldCoordinates[3];

			screenToWorldCoordinates(screenCoordinates, numScreenCoordinates, worldCoordinates);

			string pressedButton = advancedMainMenu->getPressedButton(worldCoordinates[0], worldCoordinates[1]);
			cout << "pressedButton: " << pressedButton << endl;
			//mainMenu->pressButton(button, state, x, y);
		}
	}
}

