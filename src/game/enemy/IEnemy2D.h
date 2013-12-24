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

	public:

		IEnemy2D();
		virtual ~IEnemy2D();

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
};

#endif /* IENEMY2D_H_ */
