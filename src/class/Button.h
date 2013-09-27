/*
 * Button.h
 *
 *  Created on: 24/set/2013
 *      Author: misterpup
 */

#ifndef BUTTON_H_
#define BUTTON_H_

class Button
{
	private:

		char* string;
		void* font;

		float sizeX;
		float sizeY;

		int colorSize;
		float colorButton[4];
		float colorText[4];

	public:

		Button(char* string, void* font, float buttonSize[2], float colorButton[4], float colorText[4]);
		virtual ~Button();

		void draw();
		void drawBitmapText(char *string, float x, float y);
};

#endif /* BUTTON_H_ */
