/*
 * Button.cpp
 *
 *  Created on: 24/set/2013
 *      Author: misterpup
 */

#include "Button.h"
#include "../header/utils.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string.h>
#include <iostream>

using namespace std;

Button::Button(char* string, void* font, float buttonSize[2], float colorButton[4], float colorText[4])
{
	int length = strlen(string) + 1;
	this->string = (char*)malloc(length*sizeof(char));
	strcpy(this->string, string);

	//sarebbe meglio copiare font, ma è da scoprire cosa sia l'oggetto iniziale per allocare bene la memoria
	this-> font = font;

	this->sizeX = buttonSize[0];
	this->sizeY = buttonSize[1];

	colorSize = 4;

	for(int i = 0; i < colorSize; i++)
	{
		this->colorButton[i] = colorButton[i];
		this->colorText[i] = colorText[i];
	}
}

Button::~Button()
{
	free(this->string);
}

void Button::draw()
{
	float halfDimX = sizeX/2.0f;
	float halfDimY = sizeY/2.0f;

	glColor4f(colorButton[0], colorButton[1], colorButton[2], colorButton[3]);
	glRectf(-halfDimX, halfDimY, halfDimX, -halfDimY);

	float length[2];

	getStringLenghtInWorldCoordinates(string, font, 0.0f, 0.0f, length);
	float diffX = sizeX - length[0];
	float halfDiffX = diffX/2.0f;

	//float diffY = sizeY - length[1];
	//float halfDiffY = diffY/2.0f;

	//si potrebbe centrare sulle y, disegnando carattere per carattere, e mentre disegni il primo prendi
	//i raster attuali, in particolare le y (carattere maiuscolo, si suppone sia il più alto)
	//e quindi hai l'altezza massima del testo --> forse
	glColor4f(colorText[0], colorText[1], colorText[2], colorText[3]);
	drawBitmapText(string, halfDimX - halfDiffX, 0.0f/* - length[1]/2.0f*/);
}

void Button::drawBitmapText(char *string, float x, float y)
{
	glRasterPos2f(x, y);
	glutBitmapString(font, (unsigned char*)string);
}

