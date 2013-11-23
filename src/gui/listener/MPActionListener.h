/*
 * MPActionListener.h
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#ifndef MPACTIONLISTENER_H_
#define MPACTIONLISTENER_H_

#include "ActionListener.h"

class MPActionListener: public ActionListener
{
	public:
		MPActionListener();
		MPActionListener(MPActionListener const &);
		virtual ~MPActionListener();
		virtual void actionPerformed();
		virtual ActionListener* create() const; // Virtual constructor (creation)
		virtual ActionListener* clone() const;  // Virtual constructor (copying)
};

#endif /* MPACTIONLISTENER_H_ */
