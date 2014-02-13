/*
 * QTMMActionListener.cpp
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#include "QTMMActionListener.h"
#include "../../renderer/Renderer.h"

QTMMActionListener::QTMMActionListener()
{

}

QTMMActionListener::QTMMActionListener(QTMMActionListener const &)
{
}

QTMMActionListener::~QTMMActionListener()
{
}

void QTMMActionListener::actionPerformed()
{
	Renderer* renderer = Renderer::getInstance();
	renderer->getGame()->resetGame();
	renderer->getGui()->changeToStartingMenu();
	renderer->changeToGui();
}

ActionListener* QTMMActionListener::create() const
{
	return new QTMMActionListener();
}

ActionListener* QTMMActionListener::clone() const
{
	return new QTMMActionListener(*this);
}
