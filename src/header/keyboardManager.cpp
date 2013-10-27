/*
 * keyboard.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "keyboardManager.h"
#include "globalVariables.h"
#include <GL/glut.h>
#include <math.h>

/*void modifiersOperation()
{
	int mod = glutGetModifiers();
	cout << mod << endl;

	//GLUT_ACTIVE_SHIFT - 1 Set if the Shift modifier or Caps Lock is active.
	//GLUT_ACTIVE_CTRL  - 2 Set if the Ctrl modifier is active.
	//GLUT_ACTIVE_ALT   - 4 Set if the Alt modifier is active.
}*/

//bool for key operation: true = pressed, false = unpressed
bool* stdKeyStates = new bool[256];
bool* specialKeyStates = new bool[256];
bool* modifiers = new bool[3]; //SHIFT(or CAPS LOCK)=1, CTRL=2, ALT=4

//Called when a special key is pressed
void handleSpecialKeyPress(int key, int x, int y)
{
	specialKeyStates[key] = true;
	//modifiersOperation();
}

void handleSpecialUpPress(int key, int x, int y)
{
	specialKeyStates[key] = false;
}

//Called when a standard key is pressed
void handleStdKeyPress(unsigned char key, int x, int y)
{
	//if(key == 27) //ESC
	//	mainMenu->switchInGame();

	stdKeyStates[key] = true;
}

void handleStdKeyUpPress(unsigned char key, int x, int y)
{
	stdKeyStates[key] = false;
}

void specialKeyOperation()
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
void stdKeyOperation()
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
		advancedBulletSystem->shoot(advancedPlayer);
		//bulletSystem->fire(advancedPlayer->getCurPosX(), advancedPlayer->getCurPosY(), advancedPlayer->getCurPosZ(), advancedPlayer->getDegRotation(), bulletSpeed);
		//keyStates[32] = false; //to avoid bullets to go one over the other (...)
	}
}

void keyOperation()
{
	specialKeyOperation();
	stdKeyOperation();
}

