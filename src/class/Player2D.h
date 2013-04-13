/*
 * Player2D.h
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#ifndef PLAYER2D_H_
#define PLAYER2D_H_

#include <GL/glut.h>

class Player2D
{
	private:
		float bodyDimX;
		float bodyDimY;

		float gunDimX;
		float gunDimY;

	public:
		Player2D(float bodyDimX, float bodyDimY, float gunDimX, float gunDimY);
		virtual ~Player2D();

		float getBodyDimX();
		float getBodyDimY();
		float getGunDimX();
		float getGunDimY();

		void draw(float gun_rot);
};

#endif /* PLAYER2D_H_ */
