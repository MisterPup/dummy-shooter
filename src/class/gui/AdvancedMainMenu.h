/*
 * AdvancedMainMenu.h
 *
 *  Created on: 26/ott/2013
 *      Author: misterpup
 */

#ifndef ADVANCEDMAINMENU_H_
#define ADVANCEDMAINMENU_H_

#include "Button.h"
#include <string>
#include <vector>

using namespace std;

class AdvancedMainMenu
{
	private:

		vector<Button> buttons;

		string* allText;
		int numText;

		float distanceBetweenCenterOfButton;

	public:

		AdvancedMainMenu(string allButtonLabel[], int numLabel);
		virtual ~AdvancedMainMenu();
		void draw();
		float getStartingPositionToDraw();
		string getPressedButton(float posX, float posY);
};

#endif /* ADVANCEDMAINMENU_H_ */
