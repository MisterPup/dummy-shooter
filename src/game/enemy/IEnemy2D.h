/*
 * IEnemy2D.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef IENEMY2D_H_
#define IENEMY2D_H_

#include "../shape/IShape2D.h"
#include "ai/IEnemyAI.h"

class IEnemyAI;

class IEnemy2D
{
	private:

		float posX;
		float posY;
		float posZ;
		float degRotation;
		float moveBy;
		float rotateBy;
		float distanceFromPlayerToReach;

		IShape2D* shape;

	public:

		IEnemy2D();
		virtual ~IEnemy2D();
		IEnemy2D(const IEnemy2D& other);
		IEnemy2D& operator=(const IEnemy2D& other);

		void move(bool forward);
		void rotate(bool right);

		virtual void draw() = 0;
		virtual IEnemy2D* create () const = 0; // Virtual constructor (creation)
		virtual IEnemy2D* clone () const = 0; // Virtual constructor (copying)

		float getDegRotation() const;
		void setDegRotation(float degRotation);
		float getMoveBy() const;
		void setMoveBy(float moveBy);
		float getPosX() const;
		void setPosX(float posX);
		float getPosY() const;
		void setPosY(float posY);
		float getPosZ() const;
		void setPosZ(float posZ);
		float getRotateBy() const;
		void setRotateBy(float rotateBy);
		float getDistanceFromPlayerToReach() const;
		void setDistanceFromPlayerToReach(float distanceFromPlayerToReach);

		IShape2D* getShape() const;
		void setShape(IShape2D* shape);
};

#endif /* IENEMY2D_H_ */
