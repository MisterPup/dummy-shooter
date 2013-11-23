/*
 * Keyboard.h
 *
 *  Created on: 21/nov/2013
 *      Author: misterpup
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard {

	private:

		//bool for key operation: true = pressed, false = unpressed
		static bool stdKeyStates[256];
		static bool specialKeyStates[256];
		static bool modifiers[3]; //SHIFT(or CAPS LOCK)=1, CTRL=2, ALT=4

	public:

		Keyboard();
		virtual ~Keyboard();

		static void handleSpecialKeyPress(int key, int x, int y); //Called when a special key is pressed
		static void handleSpecialUpPress(int key, int x, int y);
		static void specialKeyOperation();
		static void handleStdKeyPress(unsigned char key, int x, int y); //Called when a standard key is pressed
		static void handleStdKeyUpPress(unsigned char key, int x, int y);
		static void stdKeyOperation();
		static void keyOperation();
		//static void modifiersOperation();
};

#endif /* KEYBOARD_H_ */
