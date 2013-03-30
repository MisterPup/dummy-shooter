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

#include "Player2D.h"
#include "PlayerTriangle.h"
#include "Bullet.h"
#include "BulletSystem.h"
#include "globalVariables.h"

using namespace std;

//Called when a special key is pressed
void handleSpecialKeyPress(int key, int x, int y) 
{
	specialKeyStates[key] = true;
}

void handleSpecialUpPress(int key, int x, int y)
{
	specialKeyStates[key] = false;
}

void specialKeyOperation()
{
	if(specialKeyStates[GLUT_KEY_LEFT])
		rotation -= rotateBy;
	if(specialKeyStates[GLUT_KEY_RIGHT])
		rotation += rotateBy;
}

//Called when a key is pressed
void handleKeyPress(unsigned char key, int x, int y)
{    
	keyStates[key] = true;
}

void handleKeyUpPress(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}

//do not use "else if" because then you can't press 'w' and 'space' together
void keyOperation()
{
	if(keyStates[27]) //Escape key
	{
		exit(0); //Exit the program
	}
	if(keyStates['w']) //119
	{
		rad = 2*M_PI*rotation/360; //rotation in radiants

		newPosX += moveBy*cos(M_PI/2 + rad); //the minus is necessary because we are considering the angle with the negative x half axes ???
		newPosY += moveBy*sin(M_PI/2 + rad); //no minus sign!
	}
	if(keyStates['s']) //115
	{
		rad = 2*M_PI*rotation/360; //rotation in radiants

		newPosX -= moveBy*cos(M_PI/2 + rad); //the minus is necessary because we are considering the angle with the negative x half axes
		newPosY -= moveBy*sin(M_PI/2 + rad); //no minus sign!
	}
	if(keyStates['a']) //97
	{

	}
	if(keyStates['d']) //100
	{

	}
	if(keyStates[32]) //space
	{

	}
}

void handleMousePress(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) //quando rilascio mouse
	{
	}
}

//Initializes 3D rendering
void initRendering() 
{
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	srand(time(NULL));
}

void initObject()
{
	player1 = new PlayerTriangle(base, height);
}

//Called when the window is resized
void handleResize(int w, int h) 
{
	screenX = w;
	screenY = h;

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

void drawAxis(float length_x, float length_y, float length_z)
{
	glBegin(GL_LINES);

	glColor3f(0.0, 1.0, 0.0); //green
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(length_x, 0.0f, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(0.0f, -length_y, 0.0f);
	glVertex3f(0.0f, length_y, 0.0f);

	glColor3f(1.0, 0.0, 0.0); //red
	glVertex3f(0.0f, 0.0f, -length_z);
	glVertex3f(0.0f, 0.0f, length_z);

	glEnd();
}

void drawBoundariesOfWorld()
{
	float lineWidth = 3.0f;
	glLineWidth(lineWidth);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(eastWorld, topWorld, 0.0f);
	glVertex3f(westWorld, topWorld, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(eastWorld, bottomWorld, 0.0f);
	glVertex3f(westWorld, bottomWorld, 0.0f);
	
	glColor3f(0.0, 0.0, 1.0); //red
	glVertex3f(westWorld, bottomWorld, 0.0f);
	glVertex3f(westWorld, topWorld, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //red
	glVertex3f(eastWorld, bottomWorld, 0.0f);
	glVertex3f(eastWorld, topWorld, 0.0f);

	glEnd();
}

//Draws the 3D scene
void drawScene() 
{
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	gluLookAt(  0.0, 0.0, -15.0,		// eye position
				0.0, 0.0, 0.0,		// center
				0.0, 1.0, 0.0);		// vector UP

	specialKeyOperation();
	keyOperation();

	drawBoundariesOfWorld();

	/******Player******/
	glColor3f(0.0f, 1.0f, 0.5f);
	//drawAxis(10.0f, 10.0f, 10.0f);
	glPushMatrix();

		glTranslatef(oldPosX, oldPosY, oldPosZ);
		glRotatef(rotation, 0.0f, 0.0f, 1.0f);

		oldPosX = newPosX;
		oldPosY = newPosY;
		oldPosZ = newPosZ;

		player1->draw();
	glPopMatrix();
	/******Player******/


	/******Bullet******/
	/*glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
		bulletSystem->draw();
	glPopMatrix();*/
	/******Bullet******/

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

	glutInitWindowSize(screenX, screenY); //Set the window size
	
	//Create the window
	glutCreateWindow("Falling Objects");
	initRendering(); //Initialize rendering
	initObject();

	//Set handler functions for drawing, keypresses, and window resizes	
	glutKeyboardFunc(handleKeyPress);
	glutKeyboardUpFunc(handleKeyUpPress);
	glutSpecialFunc(handleSpecialKeyPress);
	glutSpecialUpFunc(handleSpecialUpPress);
	glutMouseFunc(handleMousePress);
	glutReshapeFunc(handleResize);
	glutDisplayFunc(drawScene);
	glutTimerFunc(updateTime, update, 0);
	
	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}









