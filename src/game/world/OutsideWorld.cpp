/*
 * OutsideWorld.cpp
 *
 *  Created on: 22/ott/2013
 *      Author: misterpup
 */

#include "OutsideWorld.h"

OutsideWorld::OutsideWorld() {
	beyondTop = false;
	beyondBottom = false;
	beyondRight = false;
	beyondLeft = false;
}

OutsideWorld::~OutsideWorld() {
}

void OutsideWorld::setBeyondTop()
{
	beyondTop = true;
	beyondBottom = false;
}
void OutsideWorld::setBeyondBottom()
{
	beyondTop = false;
	beyondBottom = true;
}
void OutsideWorld::setBeyondRight()
{
	beyondRight = true;
	beyondLeft = false;
}
void OutsideWorld::setBeyondLeft()
{
	beyondRight = false;
	beyondLeft = true;
}

bool OutsideWorld::isBeyondTop()
{
	return beyondTop;
}
bool OutsideWorld::isBeyondBottom()
{
	return beyondBottom;
}
bool OutsideWorld::isBeyondRight()
{
	return beyondRight;
}
bool OutsideWorld::isBeyondLeft()
{
	return beyondLeft;
}

