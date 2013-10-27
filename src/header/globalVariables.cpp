/*
 * globalVariables.cpp
 *
 *  Created on: 13/ott/2013
 *      Author: misterpup
 */

#include "globalVariables.h"
#include <GL/freeglut.h>

using namespace std;

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

//PlayerTriangle* player1 = new PlayerTriangle(base, height);
//BulletSystem* bulletSystem = new BulletSystem(numBullets, bulletDimY, worldBoundaries);
//PlayerTriangle* player2 = new PlayerTriangle(base, height);
//MainMenu* mainMenu = new MainMenu(buttonSize, colorButton, colorText, font);

Client* client = new Client((char*)hostname, port_number);
/*client->start(); //da fare solo quando effettivamente stò nel multiplayer*/

int numLabels = 3;
string allLabels[] = {"SinglePlayer", "MultiPlayer", "Exit Game", "Resume Game", "Quit to Main Menu", "Connect To Server"};

World2D* world = new World2D(worldSizeX, worldSizeY);
AdvancedPlayer* advancedPlayer = new AdvancedPlayer(base, height);
AdvancedPlayerSystem* advancedPlayerSystem = new AdvancedPlayerSystem(world, advancedPlayer);

AdvancedBulletSystem* advancedBulletSystem = new AdvancedBulletSystem(world, numBullets, bulletDimY);
//Keyboard* keyboard = new Keyboard(advancedPlayerSystem, advancedBulletSystem, mainMenu);
AdvancedMainMenu* advancedMainMenu = new AdvancedMainMenu(allLabels, numLabels);
