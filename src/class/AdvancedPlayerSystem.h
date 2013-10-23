/*
 * AdvancedPlayerSystem.h
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#ifndef ADVANCEDPLAYERSYSTEM_H_
#define ADVANCEDPLAYERSYSTEM_H_

#include "World2D.h"
#include "AdvancedPlayer.h"
#include <math.h>

class AdvancedPlayerSystem {

	private:

		World2D* world;
		AdvancedPlayer* player;

	public:

		AdvancedPlayerSystem(World2D* world, AdvancedPlayer* player);
		virtual ~AdvancedPlayerSystem();
		void draw();
		void rotate(bool right);
		void move(bool forward);
		void moveForward();
		void moveBackward();
};

#endif /* ADVANCEDPLAYERSYSTEM_H_ */
