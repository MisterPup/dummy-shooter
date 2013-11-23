/*
 * ActionListener.h
 *
 *  Created on: 19/nov/2013
 *      Author: misterpup
 */

#ifndef ACTIONLISTENER_H_
#define ACTIONLISTENER_H_

class ActionListener
{
	public:
		ActionListener();
		virtual ~ActionListener();
		virtual void actionPerformed() = 0;
		virtual ActionListener * create () const = 0; // Virtual constructor (creation)
		virtual ActionListener * clone () const = 0;  // Virtual constructor (copying)
};

#endif /* ACTIONLISTENER_H_ */
