/*
 * Bullet.h
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#ifndef BULLET_H_
#define BULLET_H_

#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

class Bullet
{
	private:
		float bodyDimY;

		bool shot;
		bool firstTime;

		float oldShiftX;
		float oldShiftY;
		float oldShiftZ;
		float oldGunRotation;
		float bulletPos;
		float bulletSpeed;

		float endY;

	public:
		Bullet(float bodyDimY, float endY);
		virtual ~Bullet();

		float getBodyDimY();
		bool isShot();
		void shoot(float shiftX, float shiftY, float shiftZ, float gunRotation, float bulletSpeed);

		bool isFirstTime();

		bool draw();
};

#endif /* BULLET_H_ */
