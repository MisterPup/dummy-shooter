/*
 * Game.h
 *
 *  Created on: 27/ott/2013
 *      Author: misterpup
 */

#ifndef GAME_H_
#define GAME_H_

#include "State.h"
#include <vector>

using namespace std;

class Game
{
	private:

		vector<State> states;

	public:

		Game();
		virtual ~Game();
		void createStates();
};

#endif /* GAME_H_ */
