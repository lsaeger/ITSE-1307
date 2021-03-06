// 
#pragma once
class rectangle
{
public:
	rectangle(int intpWidth, int intpHeight);
	~rectangle();
	int intHeight;
	int intWidth;
public:
	int perimeter();
	int area();
	bool issquare();
	void setWidth(int intpWidth);
	void setHeight(int intpHeight);
	int getWidth();
	int getHeight();
};

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


//







#include "stdafx.h"
#include "rectangle.h"
#include <iostream>
using namespace std;


int main()
{
	//creates 10 by 5 rectancle object
	rectangle objRect(10, 5);

	//prints out area, perimeter and if 10 by 5 is a square
	cout << "Area: " << objRect.area() << endl;
	cout << "Perimeter: " << objRect.perimeter() << endl;
	cout << "Is it square: ";
	if (objRect.issquare() == 0) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}


	//sets the obj to 20 by 20
	objRect.setHeight(20);
	objRect.setWidth(20);

	//prints out height and width
	cout << "Height: " << objRect.getHeight() << endl;
	cout << "Width: " << objRect.getWidth() << endl;

	//determines if 20 by 20 is a square
	cout << "Is it square: ";
	if (objRect.issquare() == 0) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}

    return 0;
}

