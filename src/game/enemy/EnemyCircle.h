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
		float radius = 0.2;
		int numSegments = 100;

	public:
		EnemyCircle();
		virtual ~EnemyCircle();
		void draw();
};

#endif /* ENEMYCIRCLE_H_ */
