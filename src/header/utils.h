/*
 * utils.h
 *
 *  Created on: 27/set/2013
 *      Author: misterpup
 */

#include <GL/glut.h>
#include <GL/freeglut.h>
#include "iostream"

using namespace std;

#ifndef UTILS_H_
#define UTILS_H_

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

//0 = ok
int screenToWorldCoordinates(GLfloat* screenCoordinates, int numScreenCoordinates, GLdouble worldCoordinates[3])
{
	if(numScreenCoordinates < 2)
		return -1;

	GLint viewport[4]; //var to hold the viewport info
    GLdouble modelview[16]; //var to hold the modelview info - 12, 13, 14 current x, y, z
    GLdouble projection[16]; //var to hold the projection matrix info
    GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
	glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
	glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

	winX = (float)screenCoordinates[0];
	winY = (float)viewport[3] - (float)screenCoordinates[1]; //OpenGL uses lower left corner of screen as coordinate system orign. Window system usually uses upper left corner as coordinate system orign.

	if(numScreenCoordinates == 2) //leggo la terza coordinata dal frame buffer
		glReadPixels( winX, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
	else //numScreenCoordinates > 2
		winZ = (float)screenCoordinates[2];

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldCoordinates[0], &worldCoordinates[1], &worldCoordinates[2]);

	return 0;
}

//y non funziona bene, perchè restituisce l'altezza massima del font
void getStringLenghtInWorldCoordinates(char *string, void* font, float x, float y, float length[2])
{
	glRasterPos2f(x, y);

	GLfloat rasterInitialPosition[4];
	glGetFloatv(GL_CURRENT_RASTER_POSITION, rasterInitialPosition);

	GLfloat rasterFinalPosition[4];
	glGetFloatv(GL_CURRENT_RASTER_POSITION, rasterFinalPosition);
	rasterFinalPosition[0] += glutBitmapLength(font, (unsigned char*)string);
	rasterFinalPosition[1] += glutBitmapHeight(font);

	GLdouble worldInitialCoordinates[3];
	screenToWorldCoordinates(rasterInitialPosition, 3, worldInitialCoordinates);

	GLdouble worldFinalCoordinates[3];
	screenToWorldCoordinates(rasterFinalPosition, 3, worldFinalCoordinates);

	length[0] = worldFinalCoordinates[0] - worldInitialCoordinates[0];
	if(length[0] < 0.0f)
		length[0] *= -1.0f;

	length[1] = worldFinalCoordinates[1] - worldInitialCoordinates[1];
	if(length[1] < 0.0f)
		length[1] *= -1.0f;

	//cout << worldInitialCoordinates[0] << " " << worldInitialCoordinates[1] << endl;
	//cout << worldFinalCoordinates[0] << " " << worldFinalCoordinates[1] << endl;
}

#endif /* UTILS_H_ */
