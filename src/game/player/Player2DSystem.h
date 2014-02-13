/*
 * Player2DSystem.h
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#ifndef PLAYER2DSYSTEM_H_
#define PLAYER2DSYSTEM_H_

#include "../world/World2D.h"
#include "Player2D.h"
#include <math.h>

class Player2DSystem
{

	private:

		World2D world;
		Player2D player;

	public:

		Player2DSystem();
		Player2DSystem(World2D world);
		Player2DSystem(World2D world, Player2D player);
		virtual ~Player2DSystem();
		Player2DSystem& operator=(const Player2DSystem& other);

		Player2D getPlayer();

		void draw();
		void rotate(bool right);
		void move(bool forward);
		void moveForward();
		void moveBackward();
};

#endif /* PLAYER2DSYSTEM_H_ */
