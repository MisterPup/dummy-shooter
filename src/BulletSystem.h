/*
 * BulletSystem.h
 *
 *  Created on: 25/mar/2013
 *      Author: misterpup
 */

#ifndef BULLETSYSTEM_H_
#define BULLETSYSTEM_H_

#include <vector>
#include "Bullet.h"

using namespace std;

class BulletSystem
{
	private:
		vector<Bullet> bullets;
		int numBullets;
		float bulletDimY;
		int index;

	public:
		BulletSystem(int numBullets, float bulletDimY, float worldBoundaries[4]);
		virtual ~BulletSystem();

		void fire(float shiftX, float shiftY, float shiftZ, float gunRotation, float bulletSpeed);
		void draw();
};

#endif /* BULLETSYSTEM_H_ */
