/*
 * IRenderable.h
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#ifndef IRENDERABLE_H_
#define IRENDERABLE_H_

#include <string>

using namespace std;

class IRenderable
{
	public:
		IRenderable();
		virtual ~IRenderable();

		virtual void leftClick(float x, float y) = 0;
		virtual void pressStandardKey(int key) = 0;
		virtual void pressSpecialKey(int key) = 0;
		virtual void draw() = 0;
};

#endif /* IRENDERABLE_H_ */
