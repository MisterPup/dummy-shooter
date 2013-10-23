/*
 * World2D.h
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#ifndef WORLD2D_H_
#define WORLD2D_H_

#include "OutsideWorld.h"
#include "AdvancedPlayer.h"
//#include "AdvancedBullet.h"
#include <GL/glut.h>

class World2D
{
	private:

		float sizeX;
		float sizeY;

		float leftWorld;
		float rightWorld;
		float topWorld;
		float bottomWorld;

	public:

		World2D(float sizeX, float sizeY);
		virtual ~World2D();
		void draw();
		bool isInside(float posX, float posY);
		OutsideWorld getOutsidePosition(AdvancedPlayer* player);
		//OutsideWorld getOutsidePosition(AdvancedBullet* bullet);

		float getSizeX();
		float getSizeY();
		float getLeftWorld();
		float getRightWorld();
		float getTopWorld();
		float getBottomWorld();
};

#endif /* WORLD2D_H_ */
