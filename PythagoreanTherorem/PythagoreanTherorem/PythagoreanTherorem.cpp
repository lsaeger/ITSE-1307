/*
Lillian Saeger
ITSE 1307 Spring 2019
20190208
This program takes two sides of a triangle and solves for the third side as long as the third side is across from a 90 degree angle.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int intSideA = 1;
	int intSideB = 1;
	double dblSideC = 1.0;
	
	cout << "Pythagorean Triangle Problem Solver" << endl;
	cout << endl;

	//user input
	cout << "Enter triangle side a (not the side across from the 90 degree angle): ";
	cin >> intSideA;
	cout << endl;
	cout << "Enter triangle side b (not the side across from the 90 degree angle): ";
	cin >> intSideB;
	cout << endl;

	//calculation of third side of triangle
	dblSideC = sqrt((intSideA * intSideA) + (intSideB * intSideB));

	//output
	cout << "Triangle side c has a value of: " << dblSideC << endl;

	return 0;
}

