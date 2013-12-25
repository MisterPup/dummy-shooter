/*
 * Circle.h
 *
 *  Created on: 24/dic/2013
 *      Author: misterpup
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {

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

		void draw();

		int getNumSegments() const;
		void setNumSegments(int numSegments);
		float getRadius() const;
		void setRadius(float radius);
		bool isFilled() const;
		void setFilled(bool filled);
};

#endif /* CIRCLE_H_ */