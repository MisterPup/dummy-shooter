/*
 * Bullet2DSystem.h
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#ifndef BULLET2DSYSTEM_H_
#define BULLET2DSYSTEM_H_

#include "../world/World2D.h"
#include "Bullet2D.h"
#include <vector>

using namespace std;

class Bullet2DSystem {

	private:

		World2D world;
		vector<Bullet2D> bullets;
		int numBullets;
		float bulletDimY;

	public:

		Bullet2DSystem();
		Bullet2DSystem(const World2D& world, int numBullets, float bulletDimY);
		Bullet2DSystem& operator=(const Bullet2DSystem& other);
		virtual ~Bullet2DSystem();

		const vector<Bullet2D>& getBullets() const;

		/**
		 * destroy bullet at specified index
		 */
		void destroyBullet(int index);

		/**
		 * shoot another bullet if available
		 */
		void shoot(Player2D player);

		/**
		 * Draw each bullet if inside the world, else remove it from bullets
		 */
		void draw();

		/**
		 * Check if the bullet is inside the world
		 */
		bool checkInsideWorld(const Bullet2D& bullet, int indexInBullets);
};

#endif /* BULLET2DSYSTEM_H_ */
