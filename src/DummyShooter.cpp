#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "Player2D.h"
#include "Bullet.h"
#include "BulletSystem.h"

using namespace std;

int screenX = 640;
int screenY = 400;

float shiftX = 0.0f;
float shiftY = 0.0f;
float shiftZ = 0.0f;
float gunRotation = 0.0;

int FPS = 30;
float updateTime = 1000/(float)FPS;

float bulletDimY = 0.1f;
float bulletSpeed = 0.1f;
int numBullets = 10;

BulletSystem* bulletSystem;

const float endY = 2.0f; //top of the world

//Called when a special key is pressed
void handleSpecialKeyPress(int key, int x, int y) 
{
	switch (key) 
	{	
		case GLUT_KEY_LEFT: //a
			gunRotation -= 6.0f;
			break;
		case GLUT_KEY_RIGHT: //d
			gunRotation += 6.0f;
			break;
	}
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
	glutPostRedisplay();	
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
	bulletSystem = new BulletSystem(numBullets, bulletDimY, endY);
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
	glVertex3f(-10.0f, endY, 0.0f);
	glVertex3f(10.0f, endY, 0.0f);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(-10.0f, -endY, 0.0f);
	glVertex3f(10.0f, -endY, 0.0f);

	glEnd();
}

//Draws the 3D scene
void drawScene() 
{
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	gluLookAt(  0.0, 0.0, -6.0,		// eye position //5.0, 3.0, -6.0 per vedere tutti gli assi
				0.0, 0.0, 0.0,		// center
				0.0, 1.0, 0.0);		// vector UP

	drawBoundariesOfWorld();

	//Player
	glColor3f(0.0f, 1.0f, 0.5f);
	float bodyDimX = 1.0f;
	float bodyDimY = 0.2f;

	shiftY = -endY + bodyDimY/2.0f;

	float gunDimX = 0.2f;
	float gunDimY = 0.3f;

	Player2D player1(bodyDimX, bodyDimY, gunDimX, gunDimY);

	glPushMatrix();
		glTranslatef(shiftX, -endY, shiftZ);
		player1.draw(gunRotation);
	glPopMatrix();

	//Bullet
	glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
		bulletSystem->draw();
	glPopMatrix();

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









