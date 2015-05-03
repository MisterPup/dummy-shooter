/*
 * Renderer.h
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "../gui/Gui.h"
#include "../game/Game.h"
#include "IDrawable.h"
#include "IRenderable.h"

class Renderer {
	private:
		static Renderer* instance;
		Gui* gui;
		Game* game;
		IRenderable* currentRendered; //current rendered object (gui or game)

		Renderer();

	public:

		virtual ~Renderer();
		static Renderer* getInstance();

		void setUpdateTime(float updateTime);

		Gui* getGui() const;
		Game* getGame() const;

		void changeToGui();
		void changeToGame();
		void changeToOther();
		void exitGame();

		void leftClick(float x, float y);
		void pressStandardKey(int key);
		void pressSpecialKey(int key);
		void draw();
};

#endif /* RENDERER_H_ */
