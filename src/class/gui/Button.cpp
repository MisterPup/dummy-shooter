/*
 * Button.cpp
 *
 *  Created on: 24/set/2013
 *      Author: misterpup
 */

#include "Button.h"
#include "../../header/utils.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

Button::Button(string label)
{
	this->text = label;
	font = GLUT_BITMAP_TIMES_ROMAN_24;

	sizeX = 6.0f;
	sizeY = 1.5f;

	colorSize = 4;
	float colorButton[4] = {0.0f, 1.0f, 0.5f, 0.5f};
	float colorText[4] = {0.0f, 1.0f, 0.5f, 1.0f};

	for(int i = 0; i < colorSize; i++)
	{
		this->colorButton[i] = colorButton[i];
		this->colorText[i] = colorText[i];
	}
}

Button::Button(string text, void* font, float buttonSize[2], float colorButton[4], float colorText[4])
{
	this->text = text;

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

Button::Button(const Button& other)
{
	this->text = other.text;
	this->font = other.font;
	this->sizeX = other.sizeX;
	this->sizeY = other.sizeY;
	this->colorSize = other.colorSize;
	for(int i = 0; i < colorSize; i++)
	{
		this->colorButton[i] = other.colorButton[i];
		this->colorText[i] = other.colorText[i];
	}
}

Button& Button::operator=( const Button& other )
{
	this->text = other.text;
	this->font = other.font;
	this->sizeX = other.sizeX;
	this->sizeY = other.sizeY;
	this->colorSize = other.colorSize;
	for(int i = 0; i < colorSize; i++)
	{
		this->colorButton[i] = other.colorButton[i];
		this->colorText[i] = other.colorText[i];
	}

	return *this;
}

Button::~Button()
{
}

void Button::draw()
{
	float halfDimX = sizeX/2.0f;
	float halfDimY = sizeY/2.0f;

	glColor4f(colorButton[0], colorButton[1], colorButton[2], colorButton[3]);
	glRectf(-halfDimX, halfDimY, halfDimX, -halfDimY);

	float length[2];
	getStringLenghtInWorldCoordinates((char*)text.c_str(), font, 0.0f, 0.0f, length);
	float diffX = sizeX - length[0]; //spazio rimanente lungo le x nel pulsante dopo aver inserito il testo
	float halfDiffX = diffX/2.0f;

	//float diffY = sizeY - length[1];
	//float halfDiffY = diffY/2.0f;

	//si potrebbe centrare sulle y, disegnando carattere per carattere, e mentre disegni il primo prendi
	//i raster attuali, in particolare le y (carattere maiuscolo, si suppone sia il più alto)
	//e quindi hai l'altezza massima del testo --> forse
	glColor4f(colorText[0], colorText[1], colorText[2], colorText[3]);
	drawBitmapText(text, halfDimX - halfDiffX, 0.0f/* - length[1]/2.0f*/);
}

void Button::drawBitmapText(string text, float x, float y)
{
	glRasterPos2f(x, y);
	glutBitmapString(font, (unsigned char*)text.c_str());
}

string Button::getText()
{
	return text;
}

float Button::getSizeX()
{
	return sizeX;
}

float Button::getSizeY()
{
	return sizeY;
}

void Button::setColorButton(float colorButton[4])
{
	for(int i = 0; i < colorSize; i++)
		this->colorButton[i] = colorButton[i];
}
void Button::setColorText(float colorText[4])
{
	for(int i = 0; i < colorSize; i++)
		this->colorText[i] = colorText[i];
}
