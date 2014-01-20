/*
 * Circle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "../shape/IShape2D.h"

class Circle: public IShape2D
{

	private:
		float radius;
		int num_segments;
		bool filled;

	public:
		Circle();
		Circle(float radius, int num_segments, bool filled);
		virtual ~Circle();
		Circle(const Circle& other);
		Circle& operator=(const Circle& other);

		virtual void draw();
		virtual bool isInside(float shapeX, float shapeY, float pointX, float pointY) const;

		virtual IShape2D* create() const; // Virtual constructor (creation)
		virtual IShape2D* clone() const;  // Virtual constructor (copying)

		int getNumSegments() const;
		void setNumSegments(int numSegments);
		float getRadius() const;
		void setRadius(float radius);
		bool isFilled() const;
		void setFilled(bool filled);
};

#endif /* CIRCLE_H_ */
