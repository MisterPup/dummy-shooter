/*
 * Triangle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "../shape/IShape2D.h"

class Triangle: public IShape2D
{

	private:
		float base;
		float height;

	public:
		Triangle();
		Triangle(float base, float height);
		virtual ~Triangle();
		Triangle(const Triangle& other);
		Triangle& operator=(const Triangle& other);

		virtual void draw();
		virtual bool isInside(float shapeX, float shapeY, float pointX, float pointY) const;

		virtual IShape2D* create() const; // Virtual constructor (creation)
		virtual IShape2D* clone() const;  // Virtual constructor (copying)

		float getBase() const;
		float getHeight() const;
		void setBase(float base);
		void setHeight(float height);
};

#endif /* TRIANGLE_H_ */
