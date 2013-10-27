/*
 * State.h
 *
 *  Created on: 27/ott/2013
 *      Author: misterpup
 */

#ifndef STATE_H_
#define STATE_H_

#include <string>

using namespace std;

class State {

	private:

		string label;

	public:

		State(string state);
		virtual ~State();
		string getLabel();
		bool equals(State other);
};

#endif /* STATE_H_ */
