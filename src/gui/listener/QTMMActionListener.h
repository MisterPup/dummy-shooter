/*
 * QTMMActionListener.h
 *
 *  Created on: 23/nov/2013
 *      Author: misterpup
 */

#ifndef QTMMACTIONLISTENER_H_
#define QTMMACTIONLISTENER_H_

#include "ActionListener.h"

class QTMMActionListener: public ActionListener {
	public:
		QTMMActionListener();
		QTMMActionListener(QTMMActionListener const &);
		virtual ~QTMMActionListener();
		virtual void actionPerformed();
		virtual ActionListener* create() const; // Virtual constructor (creation)
		virtual ActionListener* clone() const;  // Virtual constructor (copying)
};

#endif /* QTMMACTIONLISTENER_H_ */
