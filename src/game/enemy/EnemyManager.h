/*
 * EnemyManager.h
 *
 *  Created on: 25/dic/2013
 *      Author: misterpup
 */

#ifndef ENEMYMANAGER_H_
#define ENEMYMANAGER_H_

#include "IEnemy2D.h"
#include "../World2D.h"
#include "../Player2DSystem.h"
#include "../Bullet2DSystem.h"
#include <vector>

using namespace std;

class EnemyManager
{
	private:

		vector<IEnemy2D*> enemies;
		int maxNumEnemies;
		World2D world;

		void init();
		bool checkIfNewMustCreated();
		void createEnemy();
		void choosePositionToCreate(IEnemy2D* enemy);
		void changeAndMoveTowardObjective(IEnemy2D* enemy, Player2DSystem playerSystem);
		void checkIfHit(IEnemy2D* enemy, Bullet2DSystem bulletSystem);
		void draw(IEnemy2D* enemy);

	public:

		EnemyManager();
		EnemyManager(World2D world);
		virtual ~EnemyManager();
		EnemyManager(const EnemyManager& other);
		EnemyManager& operator=(const EnemyManager& other);

		void manage(Player2DSystem playerSystem, Bullet2DSystem bulletSystem);
};

#endif /* ENEMYMANAGER_H_ */
