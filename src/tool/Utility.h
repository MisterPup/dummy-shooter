/*
 * Utility.h
 *
 *  Created on: 20/nov/2013
 *      Author: misterpup
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <GL/glut.h>

class Utility {
	public:
		Utility();
		virtual ~Utility();

		static void drawAxis(float length_x, float length_y, float length_z);
		//0 = ok
		static int screenToWorldCoordinates(GLfloat* screenCoordinates, int numScreenCoordinates, GLdouble worldCoordinates[3]);
		//y non funziona bene, perchè restituisce l'altezza massima del font
		static void getStringLenghtInWorldCoordinates(char *string, void* font, float x, float y, float length[2]);
};

#endif /* UTILITY_H_ */
