/*
 * EnemyCircle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef ENEMYCIRCLE_H_
#define ENEMYCIRCLE_H_

#include "IEnemy2D.h"
#include "../shape/Circle.h"

class EnemyCircle: public IEnemy2D
{
	private:

	public:
		EnemyCircle();
		virtual ~EnemyCircle();

		virtual IEnemy2D* create () const;
		virtual IEnemy2D* clone () const;

		virtual void takeDecision(IEnemy2D* enemy);
		virtual void move(IEnemy2D* enemy);
		virtual void shoot(IEnemy2D* enemy);

		void draw();
};

#endif /* ENEMYCIRCLE_H_ */
