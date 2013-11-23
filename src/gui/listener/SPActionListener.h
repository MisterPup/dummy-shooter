/*
 * SPActionListener.h
 *
 *  Created on: 21/nov/2013
 *      Author: misterpup
 */

#ifndef SPACTIONLISTENER_H_
#define SPACTIONLISTENER_H_

#include "ActionListener.h"

class SPActionListener: public ActionListener
{
public:
	SPActionListener();
	SPActionListener(SPActionListener const &);
	virtual ~SPActionListener();
	virtual void actionPerformed();
	virtual ActionListener* create() const; // Virtual constructor (creation)
	virtual ActionListener* clone() const;  // Virtual constructor (copying)
};

#endif /* SPACTIONLISTENER_H_ */
