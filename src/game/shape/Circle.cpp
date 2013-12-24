/*
 * Circle.cpp
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#include "Circle.h"
#include <GL/glut.h>
#include <math.h>

Circle::Circle(float radius, int num_segments, bool filled)
{
	this->radius = radius;
	this->num_segments = num_segments;
	this->filled = filled;
}

Circle::~Circle()
{
}

void Circle::draw()
{
	if(filled)
		glBegin(GL_TRIANGLE_FAN);
	else
		glBegin(GL_LINE_LOOP);

	for(int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * M_PI * float(i) / float(num_segments); //get the current angle
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);
		glVertex2f(x, y);
	}
	glEnd();
}

int Circle::getNumSegments() const
{
	return num_segments;
}

void Circle::setNumSegments(int numSegments)
{
	num_segments = numSegments;
}

float Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(float radius)
{
	this->radius = radius;
}
