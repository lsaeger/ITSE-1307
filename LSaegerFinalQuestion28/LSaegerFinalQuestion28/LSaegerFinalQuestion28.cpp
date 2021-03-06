// 
#pragma once
class rectangle
{
private:
	int intHeight;
	int intWidth;
public:
	rectangle(int intpHeight, int intpWidth);
	~rectangle();
	int getHeight();
	void setHeight(int intpHeight);
	int getWidth();
	void setWidth(int intpWidth);
	bool issquare();
	int area();
	int perimeter();
};



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




//

#include "stdafx.h"
#include <iostream>
#include "rectangle.h"

using namespace std;


int main()
{
	//create rectangle object
	rectangle objRect(10, 20);

	//print out rectangle statistics from getters and methods
	cout << "Rectangle is 10 by 20" << endl;
	cout << "Height: " << objRect.getHeight() << endl;
	cout << "Width: " << objRect.getWidth() << endl;
	cout << "Area : " << objRect.area() << endl;
	cout << "Perimeter: " <<objRect.perimeter() << endl;
	
	//verify isquare works if rectangle not a square
	cout << "For 10 by 20, is it Square? ";
	if (objRect.issquare() == 0) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}
	
	//change height and width from setters
	objRect.setHeight(5);
	objRect.setWidth(5);

	//verify issquare works if rectangle is a square
	cout << "For 5 by 5, is it Square? ";
	if (objRect.issquare() == 0) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}

    return 0;
}

