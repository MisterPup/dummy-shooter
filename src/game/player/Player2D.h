/*
 * Player2D.h
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#ifndef PLAYER2D_H_
#define PLAYER2D_H_

#include "../../renderer/IDrawable.h"

class Player2D: public IDrawable
{
	private:

		float base; //triangle base
		float height; //triangle height

		float degRotation; //current gun rotation

		float curPosX;
		float curPosY;
		float curPosZ;

		float moveBy;
		float rotateBy;

		bool teleport;

		void drawTriangle();

	public:

		static float MOVEBY;
		static float ROTATEBY;
		static float BASE;
		static float HEIGHT;

		Player2D();
		virtual ~Player2D();
		Player2D(const Player2D& other);
		Player2D& operator=(const Player2D& other);

		void move(bool forward);
		void rotate(bool right);

		void draw();

		float getBase() const;
		float getHeight() const;
		float getCurPosX() const;
		float getCurPosY() const;
		float getCurPosZ() const;
		float getDegRotation() const;
		float getMoveBy() const;
		float getRotateBy() const;
		bool getTeleport() const;

		void setCurPosX(float curPosX);
		void setCurPosY(float curPosY);
		void setCurPosZ(float curPosZ);
		void setDegRotation(float degRotation);
		void setTeleport(bool teleport);
};

#endif /* PLAYER2D_H_ */
