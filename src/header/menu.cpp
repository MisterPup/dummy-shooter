/*
 * mouse.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "menu.h"
#include "globalVariables.h"
#include <GL/glut.h>

//Reset WindowSize
void ResetWindowSize()
{
	glutReshapeWindow(prevScreenX, prevScreenY);
	glutPositionWindow(0,0);
}

void toggleFullScreen()
{
	if(fullScreen)
	{
		ResetWindowSize();
		fullScreen = !fullScreen;
	}
	else
	{
		glutFullScreen(); //it calls
		fullScreen = !fullScreen;
	}
}

void menu(int option)
{
	switch(option)
	{
		case 'q':
			exit(0);
			break;
		case 'f':
			toggleFullScreen();
			break;
		case 't':
			teleport = !teleport;
			break;
	}
}

void initMenu()
{
	//creates graphic options submenu
	int graphicMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Toggle Full Screen", 'f');

	//creates game options submenu
	int gameMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Toggle Teleport", 't');

	// creates the main menu (right button)
	glutCreateMenu(menu);
	glutAddSubMenu("Graphic Options", graphicMenu);
	glutAddSubMenu("Game Options", gameMenu);
	glutAddMenuEntry("Quit", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


