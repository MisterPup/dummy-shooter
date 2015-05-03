/*
 * IDrawable.h
 *
 *  Created on: 14/feb/2014
 *      Author: misterpup
 */

#ifndef IDRAWABLE_H_
#define IDRAWABLE_H_

class IDrawable {

	public:
		static float updateTime; //time between current and previous frame
		IDrawable();
		virtual ~IDrawable();
};

#endif /* IDRAWABLE_H_ */
