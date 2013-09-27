/*
 * MainMenu.cpp
 *
 *  Created on: 22/set/2013
 *      Author: misterpup
 */

#include <iostream>
#include <string.h>
#include <GL/glut.h>
#include "MainMenu.h"
#include "Button.h"

using namespace std;

extern int screenToWorldCoordinates(GLfloat* screenCoordinates, int numScreenCoordinates, GLdouble worldCoordinates[3]);

MainMenu::MainMenu(float buttonSize[2], float colorButton[4], float colorText[4], void* font)
{
	numButton = 2;
	this->buttonSize = (float*)malloc(numButton*sizeof(float));

	for(int i = 0; i < numButton; i++)
		this->buttonSize[i] = buttonSize[i];


	numColor = 4;
	this->colorButton = (float*)malloc(numColor*sizeof(float));
	this->colorText = (float*)malloc(numColor*sizeof(float));

	for(int i = 0; i < numColor; i++)
	{
		this->colorButton[i] = colorButton[i];
		this->colorText[i] = colorText[i];
	}

	//sarebbe meglio copiare font, ma è da scoprire cosa sia l'oggetto iniziale per allocare bene la memoria
	this->font = font;

	numText = 5;
	allText = (const char**)malloc(numText*sizeof(const char*));

	allText[0] = "SinglePlayer";
	allText[1] = "MultiPlayer";
	allText[2] = "Exit Game";
	allText[3] = "Resume Game";
	allText[4] = "Quit to Main Menu";

	singlePlayer = false;
	multiPlayer = false;
	exitGame = false;
	inGame = false;
	resetGame = false;
}

MainMenu::~MainMenu()
{
	free(buttonSize);
	free(colorButton);
	free(colorText);

	for(int i = 0; i< numText; i++)
		free((char*)allText[i]);

	free(allText);
}

void MainMenu::drawStartingMenu()
{
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	Button singlePlayer((char*)allText[0], font, buttonSize, colorButton, colorText);
	singlePlayer.draw();
	glPopMatrix();

	Button multiPlayer((char*)allText[1], font, buttonSize, colorButton, colorText);
	multiPlayer.draw();

	glPushMatrix();
	glTranslatef(0.0f, -2.0f, 0.0f);
	Button exit((char*)allText[2], font, buttonSize, colorButton, colorText);
	exit.draw();
	glPopMatrix();
}

void MainMenu::drawSinglePlayerMenu()
{
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	Button singlePlayer((char*)allText[3], font, buttonSize, colorButton, colorText);
	singlePlayer.draw();
	glPopMatrix();

	Button multiPlayer((char*)allText[4], font, buttonSize, colorButton, colorText);
	multiPlayer.draw();
}

void MainMenu::drawMultiPlayerMenu()
{
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	Button singlePlayer((char*)allText[3], font, buttonSize, colorButton, colorText);
	singlePlayer.draw();
	glPopMatrix();

	Button multiPlayer((char*)allText[4], font, buttonSize, colorButton, colorText);
	multiPlayer.draw();
}
/*
void MainMenu::drawBitmapText(char *string,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}

void MainMenu::drawButton(float translateButton[3], float textPositionInButton[3], float buttonDimension[2], float colorButton[3], float colorText[3], char* text)
{
	float halfDimX = buttonDimension[0]/2.0f;
	float halfDimY = buttonDimension[1]/2.0f;

	glPushMatrix();
	glTranslatef(translateButton[0], translateButton[1], translateButton[2]);

	glColor4f(colorButton[0], colorButton[1], colorButton[2], colorButton[3]);
	glRectf(-halfDimX, halfDimY, halfDimX, -halfDimY);

	glColor4f(colorText[0], colorText[1], colorText[2], colorText[3]);
	drawBitmapText(text, textPositionInButton[0], textPositionInButton[1], textPositionInButton[2]);
	glPopMatrix();
}

void MainMenu::drawStartingMenu()
{
	float buttonDimension[2] = {6.0f, 1.5f};
	float colorButton[4] = {0.0f, 1.0f, 0.5f, 0.5f};
	float colorText[4] = {0.0f, 1.0f, 0.5f, 1.0f};

	float translateSP[3] = {0.0f, 2.0f, 0.0f};
	float positionSPInButton[3] = {1.25f, 0.0f, 0.0f};

	drawButton(translateSP, positionSPInButton, buttonDimension, colorButton, colorText, allText[0]);

	float translateMP[3] = {0.0f, 0.0f, 0.0f};
	float positionMPInButton[3] = {1.25f, 0.0f, 0.0f};
	drawButton(translateMP, positionMPInButton, buttonDimension, colorButton, colorText, allText[1]);

	float translateEX[3] = {0.0f, -2.0f, 0.0f};
	float positionEXInButton[3] = {0.45f, 0.0f, 0.0f};
	drawButton(translateEX, positionEXInButton, buttonDimension, colorButton, colorText, allText[2]);
}

void MainMenu::drawSinglePlayerMenu()
{
	float buttonDimension[2] = {6.0f, 1.5f};
	float colorButton[4] = {0.0f, 1.0f, 0.5f, 0.5f};
	float colorText[4] = {0.0f, 1.0f, 0.5f, 1.0f};

	float translateSP[3] = {0.0f, 2.0f, 0.0f};
	float positionSPInButton[3] = {1.25f, 0.0f, 0.0f};

	drawButton(translateSP, positionSPInButton, buttonDimension, colorButton, colorText, allText[3]);

	float translateMP[3] = {0.0f, 0.0f, 0.0f};
	float positionMPInButton[3] = {1.25f, 0.0f, 0.0f};
	drawButton(translateMP, positionMPInButton, buttonDimension, colorButton, colorText, allText[4]);
}

//da implementare
void MainMenu::drawMultiPlayerMenu()
{
	float buttonDimension[2] = {6.0f, 1.5f};
	float colorButton[4] = {0.0f, 1.0f, 0.5f, 0.5f};
	float colorText[4] = {0.0f, 1.0f, 0.5f, 1.0f};

	float translateSP[3] = {0.0f, 2.0f, 0.0f};
	float positionSPInButton[3] = {1.25f, 0.0f, 0.0f};

	drawButton(translateSP, positionSPInButton, buttonDimension, colorButton, colorText, allText[3]);

	float translateMP[3] = {0.0f, 0.0f, 0.0f};
	float positionMPInButton[3] = {1.25f, 0.0f, 0.0f};
	drawButton(translateMP, positionMPInButton, buttonDimension, colorButton, colorText, allText[4]);
}*/

void MainMenu::draw()
{
	glEnable( GL_BLEND );

	if(!inGame && !singlePlayer && !multiPlayer) //menù iniziale
		drawStartingMenu();
	else if(singlePlayer && !inGame) //menù singlePlayer
		drawSinglePlayerMenu();
	else if(multiPlayer && !inGame) //menù multiPlayer
		drawMultiPlayerMenu();

	glDisable( GL_BLEND );
}

void MainMenu::pressButtonInMainMenu(float worldX, float worldY)
{
	if(worldX < 3 && worldX > -3) //vale per tutti e tre i pulsanti
	{
		if(worldY < 2.75f && worldY > 1.25f) //SinglePlayer
		{
			singlePlayer = true;
			multiPlayer = false;
			inGame = true;
		}
		else if(worldY < 0.75f && worldY > -0.75f) //MultiPlayer
		{
			singlePlayer = false;
			multiPlayer = true;
			inGame = true;
		}
		else if(worldY < -1.25f && worldY > -2.75f) //Exit Game
		{
			singlePlayer = false;
			multiPlayer = false;
			inGame = false;
			exitGame = true;
		}
	}
}

void MainMenu::pressButtonInSinglePlayerMainMenu(float worldX, float worldY)
{
	if(worldX < 3 && worldX > -3) //vale per tutti e tre i pulsanti
	{
		if(worldY < 2.75f && worldY > 1.25f) //Resume
		{
			singlePlayer = true;
			multiPlayer = false;
			inGame = true;
		}
		else if(worldY < 0.75f && worldY > -0.75f) //Exit to Main Menu
		{
			singlePlayer = false;
			multiPlayer = false;
			inGame = false;
			resetGame = true;
		}
	}
}

void MainMenu::pressButtonInMultiPlayerMainMenu(float worldX, float worldY)
{
	if(worldX < 3 && worldX > -3) //vale per tutti e tre i pulsanti
	{
		if(worldY < 2.75f && worldY > 1.25f) //Resume
		{
			singlePlayer = false;
			multiPlayer = true;
			inGame = true;
		}
		else if(worldY < 0.75f && worldY > -0.75f) //Exit to Main Menu
		{
			singlePlayer = false;
			multiPlayer = false;
			inGame = false;
			resetGame = true;
		}
	}
}

void MainMenu::pressButton(int button, int state, int x, int y) //da modificare a seconda dello stato
{
	GLfloat screenCoordinates[2];
	int numScreenCoordinates = 2;

	screenCoordinates[0] = x;
	screenCoordinates[1] = y;

	GLdouble worldCoordinates[3];

	screenToWorldCoordinates(screenCoordinates, numScreenCoordinates, worldCoordinates);

	if(button == GLUT_LEFT_BUTTON)
	{
		if(state == GLUT_UP)
		{
			if(!inGame && !singlePlayer && !multiPlayer) //menù iniziale
				pressButtonInMainMenu(worldCoordinates[0], worldCoordinates[1]);
			else if(singlePlayer && !inGame) //menù singlePlayer
				pressButtonInSinglePlayerMainMenu(worldCoordinates[0], worldCoordinates[1]);
			else if(multiPlayer && !inGame) //menù multiPlayer
				pressButtonInMultiPlayerMainMenu(worldCoordinates[0], worldCoordinates[1]);
		}
		//else if(state == GLUT_DOWN) cambia colore del pulsante -> il colore deve essere un campo del menù
			//changeColor funzione
			//if(pulsante singleplayer)
				//pulsante singleplayer.cambia colore -> devo mantenere riferimenti a tutti i pulsanti...
		//il colore è da reimpostare in pressButtonIn
	}
}

void MainMenu::switchInGame()
{
	if(singlePlayer || multiPlayer) //altrimenti stò nel menù iniziale e non devo fare nulla
		inGame = !inGame;
}

bool MainMenu::isSinglePlayer()
{
	return singlePlayer;
}

bool MainMenu::isMultiPlayer()
{
	return multiPlayer;
}

bool MainMenu::mustExitGame()
{
	return exitGame;
}

bool MainMenu::isInGame()
{
	return inGame;
}

bool MainMenu::mustReset()
{
	return resetGame;
}

void MainMenu::gameHasBeenReset()
{
	resetGame = false;
}
