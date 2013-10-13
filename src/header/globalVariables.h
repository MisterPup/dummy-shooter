/*
 * globalVariables.h
 *
 *  Created on: 28/mar/2013
 *      Author: misterpup
 */


#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include "../class/MainMenu.h"
#include "../class/BulletSystem.h"
#include "../class/PlayerTriangle.h"
#include "../class/World2D.h"
#include "../class/AdvancedPlayer.h"
#include "../class/Client.h"

//Window dimensions
extern int prevScreenX;
extern int prevScreenY;
extern int curScreenX;
extern int curScreenY;

extern bool fullScreen;

//World boundaries
extern const float worldSizeX;
extern const float worldSizeY;

//TODO Eliminare
extern const float topWorld;
extern const float bottomWorld;
extern const float westWorld;
extern const float eastWorld;

//player can/cannot teleport when reaching world boundaries
extern bool teleport;

//Player
extern float base;
extern float height;

extern float degRotation; //rotation in degrees
extern float radRotation; //rotation in radiants

//absolute old coordinates
extern float oldPosX;
extern float oldPosY;
extern float oldPosZ;

//absolute new coordinates
extern float newPosX;
extern float newPosY;
extern float newPosZ;

//how much you move/rotate when you press buttons
extern float moveBy;
extern float rotateBy;

//Bullet
extern float bulletDimY;
extern float bulletSpeed;
extern int numBullets;

//Update time
extern int FPS;
extern float updateTime;//FPS frame per second drawn

//End of the world coordinates
extern float worldBoundaries[4];

//Gun Rotation Limits
extern const float rotationsLimit;

//Main Menu
extern float buttonSize[2];
extern float colorButton[4];
extern float colorText[4];
extern void* font;

//Client
extern const char* hostname;
extern int port_number;

//MultiPlayer
extern float newPosXOther;
extern float newPosYOther;
extern float newPosZOther;
extern float degRotationOther;

extern PlayerTriangle* player1;
extern BulletSystem* bulletSystem;
extern MainMenu* mainMenu;
extern World2D* world;
extern AdvancedPlayer* advancedPlayer;
extern Client* client;
extern PlayerTriangle* player2;

/*
#include <GL/freeglut.h>

//Window dimensions
int prevScreenX = 640;
int prevScreenY = 480;
int curScreenX = prevScreenX;
int curScreenY = prevScreenY;

bool fullScreen = false;

//World boundaries
const float worldSizeX = 10.0f;
const float worldSizeY = 8.0f;


//TODO Eliminare
const float topWorld = 4.0f;
const float bottomWorld = -topWorld;
const float westWorld = 5.0f;
const float eastWorld = -westWorld;


//player can/cannot teleport when reaching world boundaries
bool teleport = true;

//Player
float base = 0.5f;
float height = 0.5f;

float degRotation = 0.0; //rotation in degrees
float radRotation = 0.0f; //rotation in radiants

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

//Main Menu
float buttonSize[2] = {6.0f, 1.5f};
float colorButton[4] = {0.0f, 1.0f, 0.5f, 0.5f};
float colorText[4] = {0.0f, 1.0f, 0.5f, 1.0f};
void* font = GLUT_BITMAP_TIMES_ROMAN_24;

//Client
const char* hostname = "localhost";
int port_number = 5000;

//MultiPlayer
float newPosXOther = 0.0f;
float newPosYOther = 0.0f;
float newPosZOther = 0.0f;
float degRotationOther = 0.0f;
*/

#endif /* GLOBALVARIABLES_H_ */
