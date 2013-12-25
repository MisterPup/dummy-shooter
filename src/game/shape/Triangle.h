/*
 * Triangle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle
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

		float getBase() const;
		float getHeight() const;
		void setBase(float base);
		void setHeight(float height);

		void draw();
};

#endif /* TRIANGLE_H_ */