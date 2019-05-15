#include "stdafx.h"
#include "rectangle.h"


rectangle::rectangle(int intpHeight, int intpWidth)
{
	setHeight(intpHeight);
	setWidth(intpWidth);
}


rectangle::~rectangle()
{
}


int rectangle::getHeight()
{
	return this->intHeight;
}


void rectangle::setHeight(int intpHeight)
{
	if (intpHeight < 0) {
		intpHeight = 1;
	}

	this->intHeight = intpHeight;
}


int rectangle::getWidth()
{
	return this->intWidth;
}


void rectangle::setWidth(int intpWidth)
{
	if (intpWidth < 0) {
		intpWidth = 1;
	}

	this->intWidth = intpWidth;
}


bool rectangle::issquare()
{
	bool boolIsSquare = true;

	if (getHeight() == getWidth()) {
		boolIsSquare = true;
	}
	else {
		boolIsSquare = false;
	}
	
	return boolIsSquare;
}


int rectangle::area()
{
	return getHeight() * getWidth();
}


int rectangle::perimeter()
{
	return (2 * getHeight()) + (2 * getWidth());
}
