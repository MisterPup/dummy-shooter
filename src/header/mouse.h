/*
 * mouse.h
 *
 *  Created on: 13/apr/2013
 *      Author: misterpup
 */

#include "globalVariables.h"
#include <GL/glut.h>

#ifndef MOUSE_H_
#define MOUSE_H_

void handleMousePress(int button, int state, int x, int y)
{
	mainMenu->pressButton(button, state, x, y);
}


#endif /* MOUSE_H_ */
