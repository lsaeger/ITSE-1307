#include "stdafx.h"
#include "Die.h"


Die::Die()
{//default constructor
	std::srand((int)time(NULL));
	setSides(6);
	roll();
}

Die::Die(int intpSides)
{
	std::srand((int)time(NULL));
	setSides(intpSides);
	roll();
}


Die::~Die()
{
}


void Die::setSides(int intpSides)
{//sets sides to 2 if less than 2 or 20 if more than 20
	if (intpSides < 2) {
		intpSides = 2;
	}
	else if (intpSides > 20) {
		intpSides = 20;
	}
	
	this->intSides = intpSides;
}


int Die::roll()
{
	return this->intValue = rand() % this->intSides + 1;;
}


int Die::get()
{
	//returns random value
	return this->intValue;
}
