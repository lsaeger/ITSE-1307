#include "stdafx.h"
#include "rectangle.h"


rectangle::rectangle(int intpWidth, int intpHeight)
{
	setWidth(intpWidth);
	setHeight(intpHeight);
	
}


rectangle::~rectangle()
{
}


int rectangle::perimeter()
{
	
	return (2 * this->intWidth) + (2 * this->intHeight);
}


int rectangle::area()
{
	
	return this->intWidth * this->intHeight;
}


bool rectangle::issquare()
{
	bool boolTempSquare = true;

	if (this->intWidth == this->intHeight) {
		boolTempSquare = true;
	}
	else {
		boolTempSquare = false;
	}
	return boolTempSquare;
}


void rectangle::setWidth(int intpWidth)
{
	if (intpWidth > 0) {
		this->intWidth = intpWidth;
	}
	else {
		this->intWidth = 1;
	}
	
}


void rectangle::setHeight(int intpHeight)
{
	if (intpHeight > 0) {
		this->intHeight = intpHeight;
	}
	else {
		this->intHeight = 1;
	}
}


int rectangle::getWidth()
{
	
	return this->intWidth;
}


int rectangle::getHeight()
{
	
	return this->intHeight;
}
