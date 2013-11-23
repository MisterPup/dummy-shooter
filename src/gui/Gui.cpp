/*
 * Gui.cpp
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#include "Gui.h"
#include "listener/ActionListener.h"
#include "listener/ButtonActionListener.h"
#include "listener/SPActionListener.h"
#include "listener/MPActionListener.h"
#include "listener/RGActionListener.h"
#include "listener/QTMMActionListener.h"
#include "listener/EGActionListener.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

string Gui::SINGLE_PLAYER = "SinglePlayer";
string Gui::MULTI_PLAYER = "MultiPlayer";
string Gui::EXIT_GAME = "Exit Game";
string Gui::RESUME_GAME = "Resume Game";
string Gui::QUIT_TO_MAIN_MENU = "Quit To Main Menu";
string Gui::CONNECT_TO_SERVER = "Connect To Server";

Gui* Gui::instance = 0;

Gui::Gui()
{
	initMenus();

	activeMenu = &startingMenu;
}

Gui::~Gui()
{
	delete instance;
}

Gui* Gui::getInstance()
{
	if(instance == 0)
		instance = new Gui();

	return instance;
}

void Gui::initMenus()
{
	initStartingMenu();
	initSPMenu();
	initMPNotConnectedMenu();
	initMPConnectedMenu();
}

void Gui::initStartingMenu()
{
	vector<string> labels;
	labels.push_back(SINGLE_PLAYER);
	labels.push_back(MULTI_PLAYER);
	labels.push_back(EXIT_GAME);

	ActionListener* spListener = new SPActionListener();
	ActionListener* mpListener = new MPActionListener();
	ActionListener* exitListener = new EGActionListener();

	vector<ActionListener*> listeners;
	listeners.push_back(spListener);
	listeners.push_back(mpListener);
	listeners.push_back(exitListener);

	MainMenu startingMenu("Starting", labels, listeners);
	this->startingMenu = startingMenu;

	delete spListener;
	delete mpListener;
	delete exitListener;
}

void Gui::initSPMenu()
{
	vector<string> labels;
	labels.push_back(RESUME_GAME);
	labels.push_back(QUIT_TO_MAIN_MENU);

	ActionListener* rgListener = new RGActionListener();
	ActionListener* etmmListener = new QTMMActionListener();

	vector<ActionListener*> listeners;
	listeners.push_back(rgListener);
	listeners.push_back(etmmListener);

	MainMenu singlePlayerMenu("SinglePlayer", labels, listeners);
	this->singlePlayerMenu = singlePlayerMenu;

	delete rgListener;
	delete etmmListener;
}

void Gui::initMPNotConnectedMenu()
{
	vector<string> labels;
	labels.push_back(CONNECT_TO_SERVER);
	labels.push_back(QUIT_TO_MAIN_MENU);

	ActionListener* cgListener = new ButtonActionListener();
	ActionListener* qtmmListener = new QTMMActionListener();

	vector<ActionListener*> listeners;
	listeners.push_back(cgListener);
	listeners.push_back(qtmmListener);

	MainMenu multiPlayerNotConnectedMenu("MultiPlayer Not Connected", labels, listeners);
	this->multiPlayerNotConnectedMenu = multiPlayerNotConnectedMenu;

	delete cgListener;
	delete qtmmListener;
}

void Gui::initMPConnectedMenu()
{
	vector<string> labels;
	labels.push_back(RESUME_GAME);
	labels.push_back(QUIT_TO_MAIN_MENU);

	ActionListener* rgListener = new RGActionListener();
	ActionListener* qtmmListener = new QTMMActionListener();

	vector<ActionListener*> listeners;
	listeners.push_back(rgListener);
	listeners.push_back(qtmmListener);

	MainMenu multiPlayerConnectedMenu("MultiPlayer Connected", labels, listeners);
	this->multiPlayerConnectedMenu = multiPlayerConnectedMenu;

	delete rgListener;
	delete qtmmListener;
}

void Gui::changeToStartingMenu()
{
	activeMenu = &startingMenu;
}

void Gui::changeToSPMenu()
{
	activeMenu = &singlePlayerMenu;
}

void Gui::changeToMPNotConnectedMenu()
{
	activeMenu = &multiPlayerNotConnectedMenu;
}

void Gui::changeToMPConnectedMenu()
{
	activeMenu = &multiPlayerConnectedMenu;
}

void Gui::leftClick(float x, float y)
{
	activeMenu->pressButton(x, y);
}

void Gui::pressStandardKey(int key)
{
	/*if(key == 27) //ESC
	{
		if(activeMenu == &startingMenu)
			exit(0);
	}*/
}

void Gui::pressSpecialKey(int key)
{

}

void Gui::draw()
{
	activeMenu->draw();
}
