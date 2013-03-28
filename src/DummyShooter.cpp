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
#include "Bullet.h"
#include "BulletSystem.h"

using namespace std;

//Window dimensions
int screenX = 1024;
int screenY = 768;

//Position of player (except shiftY)
float shiftX = 0.0f;
float shiftY = 0.0f;
float shiftZ = 0.0f;
float gunRotation = 0.0;

//Update time
int FPS = 30;
float updateTime = 1000/(float)FPS;

//Bullet
BulletSystem* bulletSystem;
float bulletDimY = 0.1f;
float bulletSpeed = 0.1f;
int numBullets = 5;

//World boundaries
const float topWorld = 4.0f;
const float bottomWorld = -topWorld;
const float westWorld = 5.0f;
const float eastWorld = -westWorld;

float worldBoundaries[4] = {topWorld, bottomWorld, westWorld, eastWorld};

//Gun Rotation Limits
const float rotationsLimit = 45.0f;

//Called when a special key is pressed
void handleSpecialKeyPress(int key, int x, int y) 
{
	switch (key) 
	{	
		case GLUT_KEY_LEFT: //a
			if(gunRotation >= -rotationsLimit)
				gunRotation -= 6.0f;
			break;
		case GLUT_KEY_RIGHT: //d
			if(gunRotation <= rotationsLimit)
				gunRotation += 6.0f;
			break;
	}
	//we must not call here glutPostRedisplay because it will increase FPS above the set threshold
}

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
					int x, int y) //The current mouse coordinates
{    
	switch (key) 
	{	
		case 27: //Escape key
			exit(0); //Exit the program
			break;
		case 97: //a
			shiftX += 0.4f;
			break;
		case 100: //d
			shiftX -= 0.4f;
			break;
		case 32: //space
			bulletSystem->fire(shiftX, shiftY, shiftZ, gunRotation, bulletSpeed);
			break;
	}
	//we must not call here glutPostRedisplay because it will increase FPS above the set threshold
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
	bulletSystem = new BulletSystem(numBullets, bulletDimY, worldBoundaries);
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

	drawBoundariesOfWorld();


	/******Player******/
	glColor3f(0.0f, 1.0f, 0.5f);
	float bodyDimX = 1.0f;
	float bodyDimY = 0.2f;

	shiftY = bottomWorld + bodyDimY/2.0f; //when the bullet is fired, the y axis needs to be set between the gun and the player (for rotation purpose - look at bullet's draw code)

	float gunDimX = 0.2f;
	float gunDimY = 0.3f;

	Player2D player1(bodyDimX, bodyDimY, gunDimX, gunDimY);

	glPushMatrix();
		glTranslatef(shiftX, bottomWorld, shiftZ);
		player1.draw(gunRotation);
	glPopMatrix();
	/******Player******/


	/******Bullet******/
	glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
		bulletSystem->draw();
	glPopMatrix();
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
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(handleSpecialKeyPress);
	glutMouseFunc(handleMousePress);
	glutReshapeFunc(handleResize);
	glutDisplayFunc(drawScene);
	glutTimerFunc(updateTime, update, 0);
	
	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}









