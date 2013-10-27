/*
 * globalVariables.h
 *
 *  Created on: 28/mar/2013
 *      Author: misterpup
 */


#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

//#include "../class/MainMenu.h"
#include "../class/World2D.h"
#include "../class/AdvancedPlayer.h"
#include "../class/AdvancedPlayerSystem.h"
#include "../class/Client.h"
//#include "../class/input/Keyboard.h"
#include "../class/AdvancedBulletSystem.h"
#include "../class/gui/AdvancedMainMenu.h"
#include <string>

using namespace std;

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

//extern PlayerTriangle* player1;
//extern BulletSystem* bulletSystem;
//extern PlayerTriangle* player2;
//extern MainMenu* mainMenu;
extern World2D* world;
extern AdvancedPlayer* advancedPlayer;
extern Client* client;

extern AdvancedPlayerSystem* advancedPlayerSystem;
//extern Keyboard* keyboard;
extern AdvancedBulletSystem* advancedBulletSystem;
extern AdvancedMainMenu* advancedMainMenu;

extern int numLabels;
extern string allLabels[];


#endif /* GLOBALVARIABLES_H_ */
