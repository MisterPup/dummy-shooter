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
#include "../../header/utils.h"

using namespace std;
/*
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

	numText = 6;
	allText = (const char**)malloc(numText*sizeof(const char*));

	allText[0] = "SinglePlayer";
	allText[1] = "MultiPlayer";
	allText[2] = "Exit Game";
	allText[3] = "Resume Game";
	allText[4] = "Quit to Main Menu";
	allText[5] = "Connect To Server";

	singlePlayer = false;
	multiPlayer = false;
	exitGame = false;
	inGame = false;
	resetGame = false;
	connected = false;
	mustConnect = false;
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
	if(!connected)
	{
		glPushMatrix();
			glTranslatef(0.0f, 2.0f, 0.0f);
			Button connectToServer((char*)allText[5], font, buttonSize, colorButton, colorText);
			connectToServer.draw();
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
			glTranslatef(0.0f, 2.0f, 0.0f);
			Button singlePlayer((char*)allText[3], font, buttonSize, colorButton, colorText);
			singlePlayer.draw();
		glPopMatrix();
	}

	Button multiPlayer((char*)allText[4], font, buttonSize, colorButton, colorText);
	multiPlayer.draw();

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
			inGame = false;
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
		if(!connected)
		{
			if(worldY < 2.75f && worldY > 1.25f) //Connect to server
			{
				cout << "CLICK" << endl;
				singlePlayer = false;
				//multiPlayer = false;
				//inGame = false;
				mustConnect = true;
			}
			else if(worldY < 0.75f && worldY > -0.75f) //Exit to Main Menu
			{
				singlePlayer = false;
				multiPlayer = false;
				inGame = false;
				resetGame = true;
				connected = false;
			}
		}
		else
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
				//connected = false; //lo disattivo da un'altra parte
			}
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

bool MainMenu::isConnected()
{
	return connected;
}

bool MainMenu::mustConnectToServer()
{
	return mustConnect;
}

void MainMenu::gameHasBeenReset()
{
	resetGame = false;
}

void MainMenu::setConnected()
{
	connected = true;
	mustConnect = false;

	multiPlayer = true;
	inGame = true;
}

void MainMenu::cannotConnect()
{
	mustConnect = false;
}

//se sono connesso ma devo resettare il gioco, allora devo disconnettermi
bool MainMenu::checkMustDisconnect()
{
	if(resetGame && connected)
	{
		cout << "checkMustDisconnect" << endl;

		connected = false;
		return true;
	}
	else
		return false;
}
*/
