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

#include "class/PlayerTriangle.h"
#include "class/BulletSystem.h"
#include "header/globalVariables.h"
#include "header/keyboard.h"
#include "header/mouse.h"
#include "header/menu.h"

using namespace std;

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
	bulletSystem = new BulletSystem(numBullets, bulletDimY, worldBoundaries);
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

void drawAxis(float length_x, float length_y, float length_z)
{
	glBegin(GL_LINES);

	glColor3f(0.0, 1.0, 0.0); //green
	glVertex3f(-length_x, 0.0f, 0.0f);
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
	
	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(westWorld, bottomWorld, 0.0f);
	glVertex3f(westWorld, topWorld, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
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

	keyOperation();

	drawBoundariesOfWorld();

	/******Player******/
	//glColor3f(0.0f, 1.0f, 0.5f);
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


	/******Bullets******/
	glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
		bulletSystem->draw();
	glPopMatrix();
	/******Bullets******/

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
	initObject();

	initMenu();

	//Set handler functions for drawing, keypresses, and window resizes	
	glutKeyboardFunc(handleStdKeyPress);
	glutKeyboardUpFunc(handleStdKeyUpPress);
	glutSpecialFunc(handleSpecialKeyPress);
	glutSpecialUpFunc(handleSpecialUpPress);
	glutMouseFunc(handleMousePress);
	glutReshapeFunc(handleResize);

	glutDisplayFunc(drawScene);
	glutTimerFunc(updateTime, update, 0);
	
	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}
