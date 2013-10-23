/*
 * utils.h
 *
 *  Created on: 27/set/2013
 *      Author: misterpup
 */


#ifndef UTILS_H_
#define UTILS_H_

#include <GL/glut.h>

void drawAxis(float length_x, float length_y, float length_z);
//0 = ok
int screenToWorldCoordinates(GLfloat* screenCoordinates, int numScreenCoordinates, GLdouble worldCoordinates[3]);
//y non funziona bene, perchè restituisce l'altezza massima del font
void getStringLenghtInWorldCoordinates(char *string, void* font, float x, float y, float length[2]);

#endif /* UTILS_H_ */
