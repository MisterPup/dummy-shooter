/*
 * World2D.h
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#ifndef WORLD2D_H_
#define WORLD2D_H_

#include <GL/glut.h>

class World2D
{
	public:
		World2D(float sizeX, float sizeY);
		virtual ~World2D();
		float getSizeX();
		float getSizeY();
		void draw();
	private:
		float sizeX;
		float sizeY;
};

#endif /* WORLD2D_H_ */
