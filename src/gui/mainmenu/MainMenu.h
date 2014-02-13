/*
 * AdvancedMainMenu.h
 *
 *  Created on: 26/ott/2013
 *      Author: misterpup
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "../button/Button.h"
#include <string>
#include <vector>

using namespace std;

class MainMenu
{
	private:

		string menuLabel;
		vector<Button> buttons;

		static float distanceBetweenCenterOfButton;

		float getStartingPositionToDraw();

	public:

		MainMenu();
		MainMenu(string menuLabel, vector<string>allButtonLabel);
		MainMenu(string menuLabel, vector<string>allButtonLabel, vector<ActionListener*> listeners);
		virtual ~MainMenu();
		MainMenu(const MainMenu& other);
		MainMenu& operator=( const MainMenu& other );

		void draw();

		string pressButton(float posX, float posY);
		string getMenuLabel();
		string getLabelOfButton(unsigned int index);
};

#endif /* MAINMENU_H_ */
