/*
 * PlayerTriangle.h
 *
 *  Created on: 29/mar/2013
 *      Author: misterpup
 */

#include <GL/glut.h>

#ifndef PLAYERTRIANGLE_H_
#define PLAYERTRIANGLE_H_

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
