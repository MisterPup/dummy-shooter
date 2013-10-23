/*
 * keyboard.h
 *
 *  Created on: 13/apr/2013
 *      Author: misterpup
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

//Called when a special key is pressed
void handleSpecialKeyPress(int key, int x, int y);
void handleSpecialUpPress(int key, int x, int y);
//Called when a standard key is pressed
void handleStdKeyPress(unsigned char key, int x, int y);
void handleStdKeyUpPress(unsigned char key, int x, int y);
void stdKeyOperation();
void keyOperation();

#endif /* KEYBOARD_H_ */
