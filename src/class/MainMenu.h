/*
 * MainMenu.h
 *
 *  Created on: 22/set/2013
 *      Author: misterpup
 */



#ifndef MAINMENU_H_
#define MAINMENU_H_

class MainMenu
{
	private:
		bool singlePlayer;
		bool multiPlayer;
		bool exitGame;
		bool inGame;
		bool resetGame;
	public:
		char** allText;
		int numText;

		MainMenu();
		virtual ~MainMenu();
		void draw();
		void drawBitmapText(char *string,float x,float y,float z);
		void drawButton(float translateButton[3], float textPositionInButton[3], float buttonDimension[2], float colorButton[3], float colorText[3], char* text);
		void drawStartingMenu();
		void drawSinglePlayerMenu();
		void drawMultiPlayerMenu();
		void switchInGame();
		void pressButton(int button, int state, int x, int y);
		void pressButtonInMainMenu(float worldX, float worldY);
		void pressButtonInSinglePlayerMainMenu(float worldX, float worldY);
		void pressButtonInMultiPlayerMainMenu(float worldX, float worldY);
		bool isSinglePlayer();
		bool isMultiPlayer();
		bool mustExitGame();
		bool isInGame();
		bool mustReset();
		void gameHasBeenReset();
};

#endif /* MAINMENU_H_ */
