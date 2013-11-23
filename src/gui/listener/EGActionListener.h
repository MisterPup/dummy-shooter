/*
 * EGActionListener.h
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#ifndef EGACTIONLISTENER_H_
#define EGACTIONLISTENER_H_

#include "ActionListener.h"

class EGActionListener: public ActionListener {
	public:
		EGActionListener();
		EGActionListener(EGActionListener const &);
		virtual ~EGActionListener();
		virtual void actionPerformed();
		virtual ActionListener* create() const; // Virtual constructor (creation)
		virtual ActionListener* clone() const;  // Virtual constructor (copying)
};

#endif /* EGACTIONLISTENER_H_ */
