/*
 * RGActionListener.h
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#ifndef RGACTIONLISTENER_H_
#define RGACTIONLISTENER_H_

#include "ActionListener.h"

class RGActionListener: public ActionListener
{
	public:
		RGActionListener();
		RGActionListener(RGActionListener const &);
		virtual ~RGActionListener();
		virtual void actionPerformed();
		virtual ActionListener* create() const; // Virtual constructor (creation)
		virtual ActionListener* clone() const;  // Virtual constructor (copying)
};

#endif /* RGACTIONLISTENER_H_ */
