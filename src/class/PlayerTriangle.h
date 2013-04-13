/*
 * PlayerTriangle.h
 *
 *  Created on: 29/mar/2013
 *      Author: misterpup
 */

#ifndef PLAYERTRIANGLE_H_
#define PLAYERTRIANGLE_H_

#include <GL/glut.h>

class PlayerTriangle
{
	private:
		float base;
		float height;

	public:
		PlayerTriangle(float base, float height);
		virtual ~PlayerTriangle();

		float getBase();
		float getHeight();

		void draw();
};

#endif /* PLAYERTRIANGLE_H_ */
