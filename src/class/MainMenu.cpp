/*
 * MainMenu.cpp
 *
 *  Created on: 22/set/2013
 *      Author: misterpup
 */

#include <string.h>
#include <GL/glut.h>
#include "MainMenu.h"

MainMenu::MainMenu()
{
	numText = 5;
	allText = (char**)malloc(numText*sizeof(char*));

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
	for(int i = 0; i< numText; i++)
		free(allText[i]);

	free(allText);
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
}

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

void MainMenu::drawBitmapText(char *string,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

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
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		GLint viewport[4]; //var to hold the viewport info
	    GLdouble modelview[16]; //var to hold the modelview info
	    GLdouble projection[16]; //var to hold the projection matrix info
	    GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
	    GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
		glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
		glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y; //OpenGL uses lower left corner of screen as coordinate system orign. Window system usually uses upper left corner as coordinate system orign.
		glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

		//get the world coordinates from the screen coordinates
		gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

		if(!inGame && !singlePlayer && !multiPlayer) //menù iniziale
			pressButtonInMainMenu(worldX, worldY);
		else if(singlePlayer && !inGame) //menù singlePlayer
			pressButtonInSinglePlayerMainMenu(worldX, worldY);
		else if(multiPlayer && !inGame) //menù multiPlayer
			pressButtonInMultiPlayerMainMenu(worldX, worldY);
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
