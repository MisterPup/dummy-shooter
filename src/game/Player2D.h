/*
 * Player2D.h
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#ifndef PLAYER2D_H_
#define PLAYER2D_H_

class Player2D
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

	public:

		Player2D();
		Player2D(float base, float height);
		virtual ~Player2D();
		Player2D(const Player2D& other);
		Player2D& operator=(const Player2D& other);

		void move(bool forward);
		void rotate(bool right);

		void draw();
		void drawTriangle();

		float getBase();
		float getHeight();

		float getCurPosX();
		float getCurPosY();
		float getCurPosZ();

		float getDegRotation();

		float getMoveBy();
		float getRotateBy();

		bool getTeleport();

		void setCurPosX(float curPosX);
		void setCurPosY(float curPosY);
		void setCurPosZ(float curPosZ);
		void setDegRotation(float degRotation);
		void setTeleport(bool teleport);
};

#endif /* PLAYER2D_H_ */
