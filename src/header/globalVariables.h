/*
 * globalVariables.h
 *
 *  Created on: 28/mar/2013
 *      Author: misterpup
 */

#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

//Window dimensions
int prevScreenX = 1280;
int prevScreenY = 720;
int curScreenX = prevScreenX;
int curScreenY = prevScreenY;

bool fullScreen = false;

//World boundaries
const float topWorld = 4.0f;
const float bottomWorld = -topWorld;
const float westWorld = 5.0f;
const float eastWorld = -westWorld;

//player can/cannot teleport when reaching world boundaries
bool teleport = true;

//Player
PlayerTriangle* player1;
float base = 0.5f;
float height = 0.5f;

float rotation = 0.0;
float rad = 0.0f;

//absolute old coordinates
float oldPosX = 0.0f;
float oldPosY = 0.0f;
float oldPosZ = 0.0f;

//absolute new coordinates
float newPosX = 0.0f;
float newPosY = 0.0f;
float newPosZ = 0.0f;

//how much you move/rotate when you press buttons
float moveBy = 0.15f;
float rotateBy = 10.0f;

//Bullet
BulletSystem* bulletSystem;
float bulletDimY = 0.1f;
float bulletSpeed = 0.25f;
int numBullets = 5;

//Update time
int FPS = 30;
float updateTime = 1000/(float)FPS;//FPS frame per second drawn

//End of the world coordinates
float worldBoundaries[4] = {topWorld, bottomWorld, westWorld, eastWorld};

//Gun Rotation Limits
const float rotationsLimit = 45.0f;

//bool for key operation: true = pressed, false = unpressed
bool* stdKeyStates = new bool[256];
bool* specialKeyStates = new bool[256];
bool* modifiers = new bool[3]; //SHIFT(or CAPS LOCK)=1, CTRL=2, ALT=4

#endif /* GLOBALVARIABLES_H_ */