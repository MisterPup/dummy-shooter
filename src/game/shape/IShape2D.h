/*
 * IShape2D.h
 *
 *  Created on: 20/gen/2014
 *      Author: misterpup
 */

#ifndef ISHAPE2D_H_
#define ISHAPE2D_H_

class IShape2D
{
	public:
		IShape2D();
		virtual ~IShape2D();
		IShape2D(const IShape2D& other);
		IShape2D& operator=(const IShape2D& other);

		virtual void draw() = 0;
		virtual bool isInside(float shapeX, float shapeY, float pointX, float pointY) const = 0;

		virtual IShape2D* create () const = 0; // Virtual constructor (creation)
		virtual IShape2D* clone () const = 0;  // Virtual constructor (copying)
};

#endif /* ISHAPE2D_H_ */
