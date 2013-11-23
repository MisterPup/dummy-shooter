/*
 * ButtonActionListener.h
 *
 *  Created on: 19/nov/2013
 *      Author: misterpup
 */

#ifndef BUTTONACTIONLISTENER_H_
#define BUTTONACTIONLISTENER_H_

#include "ActionListener.h"

class ButtonActionListener: public ActionListener
{
	public:
		ButtonActionListener();
		ButtonActionListener(ButtonActionListener const &);
		virtual ~ButtonActionListener();
		virtual void actionPerformed();
		virtual ActionListener* create() const; // Virtual constructor (creation)
		virtual ActionListener* clone() const;  // Virtual constructor (copying)
};

#endif /* BUTTONACTIONLISTENER_H_ */
