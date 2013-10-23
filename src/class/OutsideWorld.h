/*
 * OutsideWorld.h
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#ifndef OUTSIDEWORLD_H_
#define OUTSIDEWORLD_H_

class OutsideWorld {

	private:

		bool beyondTop;
		bool beyondBottom;
		bool beyondRight;
		bool beyondLeft;

	public:

		OutsideWorld();
		virtual ~OutsideWorld();

		void setBeyondTop();
		void setBeyondBottom();
		void setBeyondRight();
		void setBeyondLeft();

		bool isBeyondTop();
		bool isBeyondBottom();
		bool isBeyondRight();
		bool isBeyondLeft();
};

#endif /* OUTSIDEWORLD_H_ */
