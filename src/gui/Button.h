/*
 * Button.h
 *
 *  Created on: 24/set/2013
 *      Author: misterpup
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "listener/ActionListener.h"
#include <string>

using namespace std;

class Button
{
	private:

		string text;
		void* font;

		float sizeX;
		float sizeY;

		int colorSize;
		float colorButton[4];
		float colorText[4];

		ActionListener* listener;

		void init();
		void drawBitmapText(string text, float x, float y);

	public:

		Button(string label);
		Button(string label, ActionListener* listener);
		Button(const Button& other);
		virtual ~Button();
		Button& operator=( const Button& other );

		void draw();
		void addActionListener(ActionListener* listener);
		void performAction();

		string getText();
		float getSizeX();
		float getSizeY();

		void setColorButton(float colorButton[4]);
		void setColorText(float colorText[4]);
};

#endif /* BUTTON_H_ */
