/*
 * AdvancedPlayer.h
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#ifndef ADVANCEDPLAYER_H_
#define ADVANCEDPLAYER_H_

class AdvancedPlayer
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
		AdvancedPlayer(float base, float height);
		virtual ~AdvancedPlayer();

		void move(bool forward);
		void rotate(bool right);

		void draw();
		void drawTriangle();

		float getBase();
		float getHeight();

		float getCurPosX();
		float getCurPosY();
		float getCurPosZ();

		float getMoveBy();
		float getRotateBy();

		bool getTeleport();
		void setTeleport(bool teleport);
};

#endif /* ADVANCEDPLAYER_H_ */
