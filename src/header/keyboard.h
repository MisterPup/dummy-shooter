/*
 * keyboard.h
 *
 *  Created on: 13/apr/2013
 *      Author: misterpup
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "globalVariables.h"
#include <GL/glut.h>

/*void modifiersOperation()
{
	int mod = glutGetModifiers();
	cout << mod << endl;

	//GLUT_ACTIVE_SHIFT - 1 Set if the Shift modifier or Caps Lock is active.
	//GLUT_ACTIVE_CTRL  - 2 Set if the Ctrl modifier is active.
	//GLUT_ACTIVE_ALT   - 4 Set if the Alt modifier is active.
}*/

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
	stdKeyStates[key] = true;
}

void handleStdKeyUpPress(unsigned char key, int x, int y)
{
	stdKeyStates[key] = false;
}

void specialKeyOperation()
{
	if(specialKeyStates[GLUT_KEY_LEFT])
		rotation -= rotateBy;
	if(specialKeyStates[GLUT_KEY_RIGHT])
		rotation += rotateBy;
}

//do not use "else if" because then you can't press 'w' and 'space' together
void stdKeyOperation()
{
	if(stdKeyStates[27]) //Escape key
	{
		exit(0); //Exit the program
	}
	if(stdKeyStates['w']) //119
	{
		rad = 2*M_PI*rotation/360; //rotation in radiants

		//rad is negative when you press LEFT, but the coordinate system is left handed, so it works well
		float toMoveX = moveBy*cos(M_PI/2 + rad);
		float toMoveY = moveBy*sin(M_PI/2 + rad);

		if(teleport)
		{
			newPosX += toMoveX;
			newPosY += toMoveY;

			//different conditions from the ones above
			if(newPosX + toMoveX > westWorld)
				newPosX -= westWorld*2 - height/2; //!! equals to newPosX = newPosx - westWorld*2 + - height/2
			else if(newPosX + toMoveX < eastWorld)
				newPosX += westWorld*2 - height/2;

			if(newPosY + toMoveY > topWorld)
				newPosY -= topWorld*2 - height/2;
			else if(newPosY + toMoveY < bottomWorld)
				newPosY += topWorld*2 - height/2;
		}
		else
		{
			if(newPosX + height/2 + toMoveX < westWorld && newPosX - height/2 + toMoveX > eastWorld)
				newPosX += toMoveX;
			if(newPosY + height/2 + toMoveY < topWorld  && newPosY - height/2 + toMoveY > bottomWorld)
				newPosY += toMoveY;
		}
	}
	if(stdKeyStates['s']) //115
	{
		rad = 2*M_PI*rotation/360; //rotation in radiants

		float toMoveX = moveBy*cos(M_PI/2 + rad);
		float toMoveY = moveBy*sin(M_PI/2 + rad);

		if(teleport)
		{
			newPosX -= toMoveX;
			newPosY -= toMoveY;

			//different conditions from the ones above
			if(newPosX - toMoveX > westWorld)
				newPosX -= westWorld*2 - height/2; //!! equals to newPosX = newPosx - westWorld*2 + - height/2
			else if(newPosX - toMoveX < eastWorld)
				newPosX += westWorld*2 - height/2;

			if(newPosY - toMoveY > topWorld)
				newPosY -= topWorld*2 - height/2;
			else if(newPosY - toMoveY < bottomWorld)
				newPosY += topWorld*2 - height/2;
		}
		else
		{
			if(newPosX + height/2 - toMoveX < westWorld && newPosX - height/2 - toMoveX > eastWorld)
				newPosX -= toMoveX;
			if(newPosY + height/2 - toMoveY < topWorld  && newPosY - height/2 - toMoveY > bottomWorld)
				newPosY -= toMoveY;
		}
	}
	if(stdKeyStates['a']) //97
	{

	}
	if(stdKeyStates['d']) //100
	{

	}
	if(stdKeyStates[32]) //space
	{
		bulletSystem->fire(oldPosX, oldPosY, oldPosZ, rotation, bulletSpeed);
		//keyStates[32] = false; //to avoid bullets to go one over the other (...)
	}
}

void keyOperation()
{
	specialKeyOperation();
	stdKeyOperation();
}


#endif /* KEYBOARD_H_ */
