#include <iostream>
#include <GL/glut.h>
#include <string.h>
#include "tool/Utility.h"
#include "Renderer.h"
#include "input/Mouse.h"
#include "input/Keyboard.h"

using namespace std;

int prevScreenX = 640;//1280;
int prevScreenY = 480;//720;
int curScreenX = prevScreenX;
int curScreenY = prevScreenY;

//Update time
int FPS = 30;
float updateTime = 1000/(float)FPS; //FPS frame per second drawn

Renderer* renderer;

void initRendering();
void initObject();
void drawScene();
void handleResize(int w, int h);
void update(int value);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(curScreenX, curScreenY); //Set the window size

	glutCreateWindow("Dummy Shooter"); //Create the window
	glutPositionWindow(50, 50);

	initRendering(); //Initialize rendering
	initObject();
	glutReshapeFunc(handleResize);

	glutDisplayFunc(drawScene);
	//glutIdleFunc(drawScene);
	glutTimerFunc(updateTime, update, 0);

	//Set handler functions for drawing, keypresses, and window resizes
	glutKeyboardFunc(Keyboard::handleStdKeyPress);
	glutKeyboardUpFunc(Keyboard::handleStdKeyUpPress);
	glutSpecialFunc(Keyboard::handleSpecialKeyPress);
	glutSpecialUpFunc(Keyboard::handleSpecialUpPress);
	glutMouseFunc(Mouse::handleMousePress);

	glutMainLoop();

	return 0;
}

//Initializes 3D rendering
void initRendering()
{
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void initObject()
{
	renderer = Renderer::getInstance();
}

void drawScene()
{
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	gluLookAt(  0.0, 0.0, -15.0,	// eye position
				0.0, 0.0, 0.0,		// center
				0.0, 1.0, 0.0);		// vector UP

	Keyboard::keyOperation();
	renderer->draw();

	glutSwapBuffers();
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

//Called every 1000/FPS milliseconds
void update(int value)
{
	glutPostRedisplay();
	glutTimerFunc(updateTime, update, 0);
}
