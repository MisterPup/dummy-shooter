/*
 * Triangle.cpp
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#include "Triangle.h"
#include <GL/glut.h>

Triangle::Triangle(float base, float height)
{
	this->base = base;
	this->height = height;
}

Triangle::~Triangle()
{
}

Triangle::Triangle()
{
	base = 0.5f;
	height = 0.5;
}

Triangle::Triangle(const Triangle& other)
{
	base = other.base;
	height = other.height;
}

Triangle& Triangle::operator =(const Triangle& other)
{
	base = other.base;
	height = other.height;

	return *this;
}

void Triangle::draw()
{
	float halfBase = base/2;
	float halfHeight = height/2;

	glBegin(GL_TRIANGLES);
		glVertex3f(-halfBase, -halfHeight, 0.0f);
		glVertex3f(halfBase, -halfHeight, 0.0f);
		//glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0f, halfHeight, 0.0f);
	glEnd();
}

//TODO still a simple ugly stub
bool Triangle::isInside(float shapeX, float shapeY, float pointX, float pointY) const
{
	//al momento costruisco giusto un rettangolo intorno al centro del triangolo
	if(pointX < shapeX + 0.5f &&  pointX > shapeX - 0.5f &&
	   pointY < shapeY + 0.5f &&  pointY > shapeY - 0.5f)
		return true;

	return false;
}

float Triangle::getBase() const
{
	return base;
}

void Triangle::setBase(float base)
{
	this->base = base;
}

float Triangle::getHeight() const
{
	return height;
}

void Triangle::setHeight(float height)
{
	this->height = height;
}

IShape2D* Triangle::create() const
{
	return new Triangle();
}

IShape2D* Triangle::clone() const
{
	return new Triangle(*this);
}
