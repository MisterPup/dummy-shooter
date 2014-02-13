/*
 * Keyboard.cpp
 *
 *  Created on: 21/nov/2013
 *      Author: misterpup
 */

#include "Keyboard.h"
#include "../renderer/Renderer.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

bool Keyboard::stdKeyStates[256];
bool Keyboard::specialKeyStates[256];
bool Keyboard::modifiers[3]; //SHIFT(or CAPS LOCK)=1, CTRL=2, ALT=4

Keyboard::Keyboard()
{

}

Keyboard::~Keyboard()
{
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
	Renderer* renderer = Renderer::getInstance();

	stdKeyStates[key] = true;
}

void Keyboard::handleStdKeyUpPress(unsigned char key, int x, int y)
{
	stdKeyStates[key] = false;
}

void Keyboard::specialKeyOperation()
{
	Renderer* renderer = Renderer::getInstance();

	for(int i = 0; i < 256; i++)
	{
		if(specialKeyStates[i])
			renderer->pressSpecialKey(i);
	}
}

//do not use "else if" because then you can't press 'w' and 'space' together
void Keyboard::stdKeyOperation()
{
	Renderer* renderer = Renderer::getInstance();

	for(int i = 0; i < 256; i++)
	{
		if(stdKeyStates[i])
			renderer->pressStandardKey(i);
	}
}

void Keyboard::keyOperation()
{
	specialKeyOperation();
	stdKeyOperation();
}

/*void modifiersOperation()
{
	int mod = glutGetModifiers();
	cout << mod << endl;

	//GLUT_ACTIVE_SHIFT - 1 Set if the Shift modifier or Caps Lock is active.
	//GLUT_ACTIVE_CTRL  - 2 Set if the Ctrl modifier is active.
	//GLUT_ACTIVE_ALT   - 4 Set if the Alt modifier is active.
}*/
