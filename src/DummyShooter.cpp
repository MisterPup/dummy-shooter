/*
 * BulletSystem.cpp
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "class/Client.h"
#include "header/globalVariables.h"
#include "header/keyboardManager.h"
#include "header/mouse.h"
#include "header/menu.h"

using namespace std;

//Initializes 3D rendering
void initRendering() 
{
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	srand(time(NULL));
}

//Called when the window is resized
void handleResize(int w, int h) 
{
	prevScreenX = curScreenX;
	prevScreenY = curScreenY;

	curScreenX = w;
	curScreenY = h;

	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                   //The camera angle
		       (double)w / (double)h,  //The width-to-height ratio
			1.0,                   //The near z clipping coordinate
			200.0);                //The far z clipping coordinate
}

//Draws the 3D scene
void drawScene() 
{
	/*if(mainMenu->mustExitGame())
		exit(0);

	if(mainMenu->mustConnectToServer())
	{
		bool connected = client->connectToServer("localhost");
		cout << "Connected: " << connected << endl;

		if(connected)
		{
			mainMenu->setConnected();
			client->startConnection();
		}
		else
			mainMenu->cannotConnect();
	}

	bool res;
	if((res = mainMenu->checkMustDisconnect()))
	{
		cout << "res: " << res << endl;
		client->disconnectFromServer();
	}

	if(mainMenu->mustReset())
	{
		newPosX = oldPosX = 0.0f;
		newPosY = oldPosY = 0.0f;
		newPosZ = oldPosZ = 0.0f;
		degRotation = 0.0f;

		mainMenu->gameHasBeenReset();
	}*/

	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	gluLookAt(  0.0, 0.0, -15.0,		// eye position
				0.0, 0.0, 0.0,		// center
				0.0, 1.0, 0.0);		// vector UP

	keyOperation();

	advancedMainMenu->draw();

	//world->draw();
	//advancedPlayerSystem->draw();
	//advancedBulletSystem->draw();
	/*mainMenu->draw();

	if(mainMenu->isInGame())
	{
		world->draw();
		advancedPlayerSystem->draw();

		if(mainMenu->isMultiPlayer())
		{
			glPushMatrix();

				glTranslatef(newPosXOther, newPosYOther, newPosZOther);
				glRotatef(degRotationOther, 0.0f, 0.0f, 1.0f);

				player2->draw();
			glPopMatrix();
		}
		//TEMP TEMP TEMP
		//------Player2------
		//glPushMatrix();

		//	glTranslatef(newPosXOther, newPosYOther, newPosZOther);
		//	glRotatef(degRotationOther, 0.0f, 0.0f, 1.0f);

		//	player2->draw();
		//glPopMatrix();
		//------Player2------
		//TEMP TEMP TEMP

		//------Bullets------
		glColor3f(0.0, 1.0, 0.0);

		glPushMatrix();
			bulletSystem->draw();
		glPopMatrix();
		//------Bullets------
	}*/

	glutSwapBuffers(); //Send the 3D scene to the screen
}

//Called every 1000/FPS milliseconds
void update(int value) 
{
	glutPostRedisplay();
	glutTimerFunc(updateTime, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(curScreenX, curScreenY); //Set the window size

	glutCreateWindow("Dummy Shooter"); //Create the window
	glutPositionWindow(0,0);
	
	initRendering(); //Initialize rendering

	initMenu();

	//Set handler functions for drawing, keypresses, and window resizes	
	glutKeyboardFunc(/*keyboard->*/handleStdKeyPress);
	glutKeyboardUpFunc(/*keyboard->*/handleStdKeyUpPress);
	glutSpecialFunc(/*keyboard->*/handleSpecialKeyPress);
	glutSpecialUpFunc(/*keyboard->*/handleSpecialUpPress);
	glutMouseFunc(handleMousePress);
	glutReshapeFunc(handleResize);

	glutDisplayFunc(drawScene);
	glutTimerFunc(updateTime, update, 0);
	
	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}
