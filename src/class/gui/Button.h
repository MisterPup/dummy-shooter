/*
 * Button.h
 *
 *  Created on: 24/set/2013
 *      Author: misterpup
 */

#ifndef BUTTON_H_
#define BUTTON_H_

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

	public:

		Button(string label);
		Button(string text, void* font, float buttonSize[2], float colorButton[4], float colorText[4]);
		Button(const Button& other);
		virtual ~Button();
		Button& operator=( const Button& other );

		void draw();
		void drawBitmapText(string text, float x, float y);
		string getText();
		float getSizeX();
		float getSizeY();
		void setColorButton(float colorButton[4]);
		void setColorText(float colorText[4]);
};

#endif /* BUTTON_H_ */
