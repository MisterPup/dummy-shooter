/*
 * Bullet2DSystem.h
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#ifndef BULLET2DSYSTEM_H_
#define BULLET2DSYSTEM_H_

#include "World2D.h"
#include "Bullet2D.h"
#include <vector>

using namespace std;

class Bullet2DSystem {

	private:

		World2D world;
		vector<Bullet2D> bullets;
		int numBullets;
		float bulletDimY;
		int bulletsShoot;

	public:

		Bullet2DSystem();
		Bullet2DSystem(World2D world, int numBullets, float bulletDimY);
		Bullet2DSystem& operator=(const Bullet2DSystem& other);
		virtual ~Bullet2DSystem();

		void shoot(Player2D player);
		void draw();
		bool checkInsideWorld(Bullet2D bullet, int indexInBullets);

		const vector<Bullet2D>& getBullets() const;
};

#endif /* BULLET2DSYSTEM_H_ */
