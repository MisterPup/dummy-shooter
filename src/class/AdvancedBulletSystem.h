/*
 * AdvancedBulletSystem.h
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#ifndef ADVANCEDBULLETSYSTEM_H_
#define ADVANCEDBULLETSYSTEM_H_

#include "World2D.h"
#include "AdvancedBullet.h"
#include <vector>

using namespace std;

class AdvancedBulletSystem {

	private:

		World2D* world;
		vector<AdvancedBullet> bullets;
		int numBullets;
		float bulletDimY;
		int bulletsShoot;

	public:

		AdvancedBulletSystem(World2D* world, int numBullets, float bulletDimY);
		virtual ~AdvancedBulletSystem();

		void shoot(AdvancedPlayer* player);
		void draw();
		bool checkInsideWorld(AdvancedBullet* bullet, int indexInBullets);
};

#endif /* ADVANCEDBULLETSYSTEM_H_ */
