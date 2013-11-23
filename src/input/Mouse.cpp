/*
 * Mouse.cpp
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#include "../Renderer.h"
#include "Mouse.h"
#include "../tool/Utility.h"
#include <GL/glut.h>

Mouse::Mouse()
{

}

Mouse::~Mouse()
{
}

void Mouse::handleMousePress(int button, int state, int x, int y)
{
	GLfloat screenCoordinates[2];
	int numScreenCoordinates = 2;

	screenCoordinates[0] = x;
	screenCoordinates[1] = y;

	GLdouble worldCoordinates[3];

	Utility::screenToWorldCoordinates(screenCoordinates, numScreenCoordinates, worldCoordinates);

	if(button == GLUT_LEFT_BUTTON)
	{
		if(state == GLUT_UP)
		{
			Renderer* renderer = Renderer::getInstance();
			renderer->leftClick(worldCoordinates[0], worldCoordinates[1]);
		}
		else if(state == GLUT_DOWN)
		{

		}
	}
	else if(button == GLUT_RIGHT_BUTTON)
	{

	}
}
