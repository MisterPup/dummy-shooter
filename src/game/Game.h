/*
 * Game.h
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#ifndef GAME_H_
#define GAME_H_

#include "../renderer/IRenderable.h"
#include "world/World2D.h"
#include "bullet/Bullet2DSystem.h"
#include "player/Player2DSystem.h"
#include "enemy/EnemyManager.h"

class Game: public IRenderable
{
	private:

		static Game* instance;

		World2D world;
		Player2DSystem playerSystem;
		Bullet2DSystem bulletSystem;
		EnemyManager enemyManager;

		bool singlePlayer;

		Game();
		void initObject();

		void drawSinglePlayer();
		void drawMultiPlayer();
		void resetSinglePlayerGame();
		void resetMultiPlayerGame();

	public:

		virtual ~Game();
		static Game* getInstance();

		void initSinglePlayerGame();
		bool initMultiPlayerGame();

		void resetGame();

		World2D getWorld();
		Player2DSystem getPlayerSystem();
		Bullet2DSystem getBulletSystem();

		void leftClick(float x, float y);
		void pressStandardKey(int key);
		void pressSpecialKey(int key);
		void draw();
};

#endif /* GAME_H_ */
