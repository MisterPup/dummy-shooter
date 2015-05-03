/*
 * Bullet2D.h
 *
 *  Created on: 23/ott/2013
 *      Author: misterpup
 */

#ifndef BULLET2D_H_
#define BULLET2D_H_

#include "../../renderer/IDrawable.h"

/**
 * Line bullet
 */
class Bullet2D: public IDrawable
{
	private:

		float bodyDimY; //bullet Y dimension
		float bulletSpeed; //how much the bullet moves each frame
		float bulletPos; //bullet Y current position

		//shoot coordinates and inclination
		float shootPosX;
		float shootPosY;
		float shootPosZ;
		float shootRotation;

	public:

		Bullet2D(float bodyDimY,
				float shootPosX, float shootPosY, float shootPosZ,
				float shootRotation);
		virtual ~Bullet2D();

		float getPosX() const;
		float getPosY() const;
		float getBodyDimY() const;

		void draw();
};

#endif /* BULLET2D_H_ */
