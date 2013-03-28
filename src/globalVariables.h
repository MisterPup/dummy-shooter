/*
 * globalVariables.h
 *
 *  Created on: 28/mar/2013
 *      Author: misterpup
 */

#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

//Window dimensions
int screenX = 1024;
int screenY = 768;

//World boundaries
const float topWorld = 4.0f;
const float bottomWorld = -topWorld;
const float westWorld = 5.0f;
const float eastWorld = -westWorld;

//Player
Player2D* player1;
float bodyDimX = 1.0f;
float bodyDimY = 0.2f;

//Gun
float gunDimX = 0.2f;
float gunDimY = 0.3f;

//Position of player (except shiftY)
float shiftX = 0.0f;
float shiftY = bottomWorld + bodyDimY/2.0f; //when the bullet is fired, the y axis needs to be set between the gun and the player (for rotation purpose - look at bullet's draw code)
float shiftZ = 0.0f;
float gunRotation = 0.0;

//Bullet
BulletSystem* bulletSystem;
float bulletDimY = 0.1f;
float bulletSpeed = 0.1f;
int numBullets = 5;

//Update time
int FPS = 30;
float updateTime = 1000/(float)FPS;

float worldBoundaries[4] = {topWorld, bottomWorld, westWorld, eastWorld};

//Gun Rotation Limits
const float rotationsLimit = 45.0f;

#endif /* GLOBALVARIABLES_H_ */
