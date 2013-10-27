/*
 * State.cpp
 *
 *  Created on: 27/ott/2013
 *      Author: misterpup
 */

#include "State.h"

State::State(string label)
{
	this->label = label;
}

State::~State()
{
}

string State::getLabel()
{
	return label;
}

bool State::equals(State other)
{
	return label.compare(other.label);
}
