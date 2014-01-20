/*
 * IEnemy2D.cpp
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#include "IEnemy2D.h"
#include "math.h"

IEnemy2D::IEnemy2D()
{
	posX = 0.0f;
	posY = 0.0f;
	posZ = 0.0f;
	degRotation = 0.0f;
	moveBy = 0.15f;
	rotateBy = 10.0f;
	distanceFromPlayerToReach = 2.0f;
	shape = 0;
}

IEnemy2D::~IEnemy2D()
{
}

IEnemy2D::IEnemy2D(const IEnemy2D& other)
{
	posX = other.posX;
	posY = other.posY;
	posZ = other.posZ;
	degRotation = other.degRotation;
	moveBy = other.moveBy;
	rotateBy = other.rotateBy;
	distanceFromPlayerToReach = other.distanceFromPlayerToReach;
	shape = other.getShape()->clone();
}

IEnemy2D& IEnemy2D::operator =(const IEnemy2D& other)
{
	posX = other.posX;
	posY = other.posY;
	posZ = other.posZ;
	degRotation = other.degRotation;
	moveBy = other.moveBy;
	rotateBy = other.rotateBy;
	distanceFromPlayerToReach = other.distanceFromPlayerToReach;
	shape = other.getShape()->clone();

	return *this;
}

void IEnemy2D::move(bool forward)
{
	float radRotation = 2*M_PI*degRotation/360; //rotation in radiants

	//radRotation is negative when you press LEFT
	float toMoveX = moveBy*cos(M_PI/2 + radRotation);
	float toMoveY = moveBy*sin(M_PI/2 + radRotation);

	if(forward)
	{
		posX += toMoveX;
		posY += toMoveY;
	}
	else
	{
		posX -= toMoveX;
		posY -= toMoveY;
	}
}

void IEnemy2D::rotate(bool right)
{
	if(right)
		degRotation += rotateBy;
	else
		degRotation -= rotateBy;

	if(degRotation > 360)
		degRotation -= 360;

	if(degRotation < 0)
		degRotation += 360;
}

float IEnemy2D::getDegRotation() const
{
	return degRotation;
}

void IEnemy2D::setDegRotation(float degRotation)
{
	this->degRotation = degRotation;
}

float IEnemy2D::getMoveBy() const
{
	return moveBy;
}

void IEnemy2D::setMoveBy(float moveBy)
{
	this->moveBy = moveBy;
}

float IEnemy2D::getPosX() const
{
	return posX;
}

void IEnemy2D::setPosX(float posX)
{
	this->posX = posX;
}

float IEnemy2D::getPosY() const
{
	return posY;
}

void IEnemy2D::setPosY(float posY)
{
	this->posY = posY;
}

float IEnemy2D::getPosZ() const
{
	return posZ;
}

void IEnemy2D::setPosZ(float posZ)
{
	this->posZ = posZ;
}

float IEnemy2D::getRotateBy() const
{
	return rotateBy;
}

void IEnemy2D::setRotateBy(float rotateBy)
{
	this->rotateBy = rotateBy;
}

float IEnemy2D::getDistanceFromPlayerToReach() const
{
	return distanceFromPlayerToReach;
}

void IEnemy2D::setDistanceFromPlayerToReach(float distanceFromPlayerToReach)
{
	this->distanceFromPlayerToReach = distanceFromPlayerToReach;
}

IShape2D* IEnemy2D::getShape() const
{
	return shape;
}

void IEnemy2D::setShape(IShape2D* shape)
{
	this->shape = shape->clone();
}
