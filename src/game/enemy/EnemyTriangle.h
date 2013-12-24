/*
 * EnemyTriangle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef ENEMYTRIANGLE_H_
#define ENEMYTRIANGLE_H_

#include "IEnemy2D.h"

class EnemyTriangle: public IEnemy2D
{
	public:
		EnemyTriangle();
		virtual ~EnemyTriangle();
		virtual void draw();
};

#endif /* ENEMYTRIANGLE_H_ */
