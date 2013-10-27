/*
 * Keyboard.h
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "../AdvancedPlayerSystem.h"
#include "../AdvancedBulletSystem.h"
//#include "../MainMenu.h"

class Keyboard {

	private:

		//bool for key operation: true = pressed, false = unpressed
		bool* stdKeyStates;
		bool* specialKeyStates;
		bool* modifiers; //SHIFT(or CAPS LOCK)=1, CTRL=2, ALT=4

		AdvancedPlayerSystem* playerSystem;
		AdvancedBulletSystem* bulletSystem;
		//MainMenu* mainMenu;

	public:

		Keyboard(AdvancedPlayerSystem* advancedPlayerSystem, AdvancedBulletSystem* bulletSystem/*, MainMenu* mainMenu*/);
		virtual ~Keyboard();

		//Called when a special key is pressed
		void handleSpecialKeyPress(int key, int x, int y);
		void handleSpecialUpPress(int key, int x, int y);
		//Called when a standard key is pressed
		void handleStdKeyPress(unsigned char key, int x, int y);
		void handleStdKeyUpPress(unsigned char key, int x, int y);
		void stdKeyOperation();
		void keyOperation();
		void specialKeyOperation();
};

#endif /* KEYBOARD_H_ */
