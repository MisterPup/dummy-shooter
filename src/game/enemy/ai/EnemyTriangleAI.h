/*
 * EnemyTriangleAI.h
 *
 *  Created on: 01/mar/2014
 *      Author: misterpup
 */

#ifndef ENEMYTRIANGLEAI_H_
#define ENEMYTRIANGLEAI_H_

#include "IEnemyAI.h"

class EnemyTriangleAI: public IEnemyAI
{
	public:
		EnemyTriangleAI(World2D world, IEnemy2D* enemy, Player2DSystem playerSystem);
		virtual ~EnemyTriangleAI();

		virtual void takeDecision();
		virtual void move();
		virtual void shoot();
};

#endif /* ENEMYTRIANGLEAI_H_ */
