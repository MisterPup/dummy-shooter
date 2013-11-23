/*
 * Mouse.h
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#ifndef MOUSE_H_
#define MOUSE_H_

class Mouse
{
	public:
		Mouse();
		virtual ~Mouse();

		static void handleMousePress(int button, int state, int x, int y);
};

#endif /* MOUSE_H_ */
