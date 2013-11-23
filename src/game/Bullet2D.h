/*
 * Bullet2D.h
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#ifndef BULLET2D_H_
#define BULLET2D_H_

class Bullet2D {

	private:

		float bodyDimY;
		float bulletSpeed;
		float bulletPos;

		float shootPosX;
		float shootPosY;
		float shootPosZ;
		float shootRotation;

	public:

		Bullet2D(float bodyDimY, float shootPosX, float shootPosY, float shootPosZ, float shootRotation);
		virtual ~Bullet2D();

		float getPosX();
		float getPosY();

		void draw();
};

#endif /* BULLET2D_H_ */
