/*
 * ButtonActionListener.cpp
 *
 *  Created on: 19/nov/2013
 *      Author: misterpup
 */

#include "ButtonActionListener.h"
#include <iostream>

using namespace std;

ButtonActionListener::ButtonActionListener() 
{

}

ButtonActionListener::~ButtonActionListener() 
{
}

ButtonActionListener::ButtonActionListener(ButtonActionListener const &)
{
}

void ButtonActionListener::actionPerformed()
{
	cout << "ButtonActionListener" << endl;
}

ActionListener* ButtonActionListener::create() const
{
	return new ButtonActionListener();
}

ActionListener* ButtonActionListener::clone() const
{
	return new ButtonActionListener(*this);
}
