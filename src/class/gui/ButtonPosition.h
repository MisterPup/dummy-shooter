/*
 * ButtonPosition.h
 *
 *  Created on: 26/ott/2013
 *      Author: misterpup
 */

#ifndef BUTTONPOSITION_H_
#define BUTTONPOSITION_H_

#include "Button.h"

class ButtonPosition
{
	private:

		float posX;
		float posY;
		Button* button;

	public:

		ButtonPosition(float position[2], Button button);
		virtual ~ButtonPosition();
};

#endif /* BUTTONPOSITION_H_ */
