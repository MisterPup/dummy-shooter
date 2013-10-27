/*
 * AdvancedMainMenu.cpp
 *
 *  Created on: 26/ott/2013
 *      Author: misterpup
 */

#include "AdvancedMainMenu.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

AdvancedMainMenu::AdvancedMainMenu(string allButtonLabel[], int numLabel)
{
	numText = numLabel;
	allText = new string[numText];

	for(int i = 0; i < numText; i++)
		allText[i] = allButtonLabel[i];

	distanceBetweenCenterOfButton = 2.0f;

	for(int i = 0; i < numText; i++)
	{
		Button newButton(allText[i]);
		buttons.push_back(newButton);
	}
}

AdvancedMainMenu::~AdvancedMainMenu()
{
	delete [] allText;
}

float AdvancedMainMenu::getStartingPositionToDraw()
{
	int size = buttons.size();

	if(size <= 0)
		return 0;

	Button firstButton = buttons.at(0);
	float buttonSizeY = firstButton.getSizeY();
	float distanceBetweenButton = distanceBetweenCenterOfButton - buttonSizeY;

	float sizeAllButton = buttonSizeY;

	if(size > 1)
		sizeAllButton = buttonSizeY*size + distanceBetweenButton*(size - 1);

	float startingPosToDraw = sizeAllButton/2 - buttonSizeY/2; //= 0 per un solo pulsante

	return startingPosToDraw;
}

void AdvancedMainMenu::draw()
{
	int size = buttons.size();

	if(size <= 0)
		return;

	float startingPosToDraw = getStartingPositionToDraw();
	float posToDraw = startingPosToDraw;

	glEnable(GL_BLEND);
	for(int i = 0; i < size; i++)
	{
		glPushMatrix();
			glTranslatef(0.0f, posToDraw, 0.0f);
			Button* curButton = &buttons.at(i);
			curButton->draw();
		glPopMatrix();
		posToDraw -= distanceBetweenCenterOfButton;
	}
	glDisable(GL_BLEND);
}

string AdvancedMainMenu::getPressedButton(float posX, float posY)
{
	int size = buttons.size();

	string labelOfPressedButton = "";

	if(size <= 0)
		return labelOfPressedButton;

	Button firstButton = buttons.at(0);
	float buttonSizeX = firstButton.getSizeX();
	float buttonSizeY = firstButton.getSizeY();

	if(fabs(posX) > buttonSizeX/2) //nessun pulsante premuto
		return labelOfPressedButton;

	float startingPosToDraw = getStartingPositionToDraw();
	float posToDraw = startingPosToDraw;

	for(int i = 0; i < size; i++)
	{
		float maxButton = posToDraw + buttonSizeY/2;
		float minButton = posToDraw - buttonSizeY/2;

		if(posY < maxButton && posY > minButton)
		{
			Button* curButton = &buttons.at(i);
			return curButton->getText();
		}
		posToDraw -= distanceBetweenCenterOfButton;
	}
	return labelOfPressedButton;
}
