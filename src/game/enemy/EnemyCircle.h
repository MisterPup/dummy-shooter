/*
 * EnemyCircle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef ENEMYCIRCLE_H_
#define ENEMYCIRCLE_H_

#include "IEnemy2D.h"

class EnemyCircle: public IEnemy2D
{
	private:
		float distanceFromPlayerToReach;

	public:
		EnemyCircle();
		virtual ~EnemyCircle();
		void draw();
		float getDistanceFromPlayerToReach() const;
		void setDistanceFromPlayerToReach(float distanceFromPlayerToReach);
};

#endif /* ENEMYCIRCLE_H_ */
