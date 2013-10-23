/*
 * AdvancedBullet.h
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#ifndef ADVANCEDBULLET_H_
#define ADVANCEDBULLET_H_

class AdvancedBullet {

	private:

		float bodyDimY;
		float bulletSpeed;
		float bulletPos;

		float shootPosX;
		float shootPosY;
		float shootPosZ;
		float shootRotation;

	public:

		AdvancedBullet(float bodyDimY, float shootPosX, float shootPosY, float shootPosZ, float shootRotation);
		virtual ~AdvancedBullet();

		float getPosX();
		float getPosY();

		void draw();
};

#endif /* ADVANCEDBULLET_H_ */
