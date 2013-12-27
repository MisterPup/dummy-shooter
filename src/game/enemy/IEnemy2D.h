/*
 * IEnemy2D.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef IENEMY2D_H_
#define IENEMY2D_H_

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

	public:

		IEnemy2D();
		virtual ~IEnemy2D();
		IEnemy2D(const IEnemy2D& other);
		IEnemy2D& operator=(const IEnemy2D& other);

		void move(bool forward);
		void rotate(bool right);

		virtual void draw() = 0;

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
};

#endif /* IENEMY2D_H_ */
