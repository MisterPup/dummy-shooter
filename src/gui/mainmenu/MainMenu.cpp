/*
 * MainMenu.cpp
 *
 *  Created on: 26/ott/2013
 *      Author: misterpup
 */

#include "MainMenu.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

float MainMenu::distanceBetweenCenterOfButton = 2.0f;

MainMenu::MainMenu()
{
	menuLabel = "";
}

MainMenu::MainMenu(string menuLabel, vector<string>allButtonLabel)
{
	this->menuLabel = menuLabel;

	for(unsigned int i = 0; i < allButtonLabel.size(); i++)
	{
		Button newButton(allButtonLabel.at(i));
		buttons.push_back(newButton);
	}
}

MainMenu::MainMenu(string menuLabel, vector<string>allButtonLabel, vector<ActionListener*> listeners)
{
	this->menuLabel = menuLabel;

	for(unsigned int i = 0; i < allButtonLabel.size(); i++)
	{
		Button newButton(allButtonLabel.at(i), listeners.at(i));
		buttons.push_back(newButton);
	}
}

MainMenu::~MainMenu()
{
}

MainMenu::MainMenu(const MainMenu& other)
{
	menuLabel = other.menuLabel;

	buttons.clear();

	for(unsigned int i = 0; i < other.buttons.size(); i++)
	{
		Button newButton((Button)other.buttons.at(i));
		buttons.push_back(newButton);
	}
}

MainMenu& MainMenu::operator=( const MainMenu& other )
{
	if(this != &other)
	{
		menuLabel = other.menuLabel;

		buttons.clear();

		for(unsigned int i = 0; i < other.buttons.size(); i++)
		{
			Button newButton((Button)other.buttons.at(i));
			buttons.push_back(newButton);
		}
	}

	return *this;
}

float MainMenu::getStartingPositionToDraw()
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

void MainMenu::draw()
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

string MainMenu::pressButton(float posX, float posY)
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

	for(unsigned int i = 0; i < size; i++)
	{
		float maxButton = posToDraw + buttonSizeY/2;
		float minButton = posToDraw - buttonSizeY/2;

		if(posY < maxButton && posY > minButton)
		{
			Button* curButton = &buttons.at(i);
			curButton->performAction();
			//cout << curButton->getText() << endl;
			return curButton->getText();
		}
		posToDraw -= distanceBetweenCenterOfButton;
	}
	return labelOfPressedButton;
}

string MainMenu::getMenuLabel()
{
	return menuLabel;
}

string MainMenu::getLabelOfButton(unsigned int index)
{
	if(index < buttons.size())
		return buttons.at(index).getText();

	return "";
}
