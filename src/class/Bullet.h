/*
 * Bullet.h
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

#ifndef BULLET_H_
#define BULLET_H_

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

		float topWorld;
		float bottomWorld;
		float westWorld;
		float eastWorld;		

	public:
		Bullet(float bodyDimY, float worldBoundaries[4]);
		virtual ~Bullet();

		float getBodyDimY();
		bool isShot();
		void shoot(float shiftX, float shiftY, float shiftZ, float gunRotation, float bulletSpeed);

		bool isFirstTime();

		bool draw();
};

#endif /* BULLET_H_ */
