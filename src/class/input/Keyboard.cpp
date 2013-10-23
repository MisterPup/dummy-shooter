/*
 * Keyboard.cpp
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#include "Keyboard.h"
#include <GL/glut.h>

Keyboard::Keyboard(AdvancedPlayerSystem* advancedPlayerSystem, BulletSystem* bulletSystem, MainMenu* mainMenu) {
	this->advancedPlayerSystem = advancedPlayerSystem;
	this->bulletSystem = bulletSystem;
	this->mainMenu = mainMenu;

	//bool for key operation: true = pressed, false = unpressed
	stdKeyStates = new bool[256];
	specialKeyStates = new bool[256];
	modifiers = new bool[3]; //SHIFT(or CAPS LOCK)=1, CTRL=2, ALT=4
}

Keyboard::~Keyboard() {
}

//Called when a special key is pressed
void Keyboard::handleSpecialKeyPress(int key, int x, int y)
{
	specialKeyStates[key] = true;
	//modifiersOperation();
}

void Keyboard::handleSpecialUpPress(int key, int x, int y)
{
	specialKeyStates[key] = false;
}

//Called when a standard key is pressed
void Keyboard::handleStdKeyPress(unsigned char key, int x, int y)
{
	if(key == 27) //ESC
		mainMenu->switchInGame();

	stdKeyStates[key] = true;
}

void Keyboard::handleStdKeyUpPress(unsigned char key, int x, int y)
{
	stdKeyStates[key] = false;
}

void Keyboard::specialKeyOperation()
{
	if(specialKeyStates[GLUT_KEY_RIGHT])
	{
		advancedPlayerSystem->rotate(true);
	}
	if(specialKeyStates[GLUT_KEY_LEFT])
	{
		advancedPlayerSystem->rotate(false);
	}
}

//do not use "else if" because then you can't press 'w' and 'space' together
void Keyboard::stdKeyOperation()
{
	//if(stdKeyStates[27]) //Escape key gestita senza buffer
	//{
	//	mainMenu->switchInGame();
	//	//exit(0); //Exit the program
	//}
	if(stdKeyStates['w']) //119
	{
		advancedPlayerSystem->move(true);
	}
	if(stdKeyStates['s']) //115
	{
		advancedPlayerSystem->move(false);
	}
	if(stdKeyStates['a']) //97
	{

	}
	if(stdKeyStates['d']) //100
	{

	}
	if(stdKeyStates[32]) //space
	{
		//bulletSystem->fire(advancedPlayer->getCurPosX(), advancedPlayer->getCurPosY(), advancedPlayer->getCurPosZ(), advancedPlayer->getDegRotation(), bulletSpeed);
		//keyStates[32] = false; //to avoid bullets to go one over the other (...)
	}
}

void Keyboard::keyOperation()
{
	specialKeyOperation();
	stdKeyOperation();
}
