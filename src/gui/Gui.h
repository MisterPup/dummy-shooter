/*
 * Gui.h
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#ifndef GUI_H_
#define GUI_H_

#include "../renderer/IRenderable.h"
#include "mainmenu/MainMenu.h"
#include <string>

using namespace std;

class Gui: public IRenderable
{
	private:

		static Gui* instance;
		MainMenu startingMenu;
		MainMenu singlePlayerMenu;
		MainMenu multiPlayerNotConnectedMenu;
		MainMenu multiPlayerConnectedMenu;
		MainMenu* activeMenu;

		static string SINGLE_PLAYER;
		static string MULTI_PLAYER;
		static string EXIT_GAME;
		static string RESUME_GAME;
		static string QUIT_TO_MAIN_MENU;
		static string CONNECT_TO_SERVER;

		Gui();

	public:

		virtual ~Gui();
		static Gui* getInstance();

		void initMenus();
		void initStartingMenu();
		void initSPMenu();
		void initMPNotConnectedMenu();
		void initMPConnectedMenu();

		void changeToSPMenu();
		void changeToStartingMenu();
		void changeToMPNotConnectedMenu();
		void changeToMPConnectedMenu();

		void leftClick(float x, float y);
		void pressStandardKey(int key);
		void pressSpecialKey(int key);
		void draw();

};

#endif /* GUI_H_ */
