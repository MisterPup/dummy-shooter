/*
 * IEnemyAI.h
 *
 *  Created on: 01/mar/2014
 *      Author: misterpup
 */

#ifndef IENEMYAI_H_
#define IENEMYAI_H_

#include "../../world/World2D.h"
#include "../../player/Player2DSystem.h"
#include "../IEnemy2D.h"

class IEnemy2D;

class IEnemyAI
{
	private:
		World2D world;
		Player2DSystem playerSystem;

	public:
		IEnemyAI(World2D world, IEnemy2D* enemy, Player2DSystem playerSystem);
		virtual ~IEnemyAI();
		virtual void takeDecision() = 0;
		virtual void move() = 0;
		virtual void shoot() = 0;

		Player2DSystem getPlayerSystem() const;
		void setPlayerSystem(Player2DSystem& playerSystem);
		World2D getWorld() const;
		void setWorld(World2D& world);
};

#endif /* IENEMYAI_H_ */
