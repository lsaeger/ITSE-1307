/*
Lillian Saeger
ITSE 1307 Spring 2019
20190221
This program is designed to calculate c = (ab)/(a-b)  given a and b by the user.
*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	double dblnum1 = 0.0;
	double dblnum2 = 0.0;
	double dblnum3 = 0.0;

	cout << "This program will take two doubles (decimal numbers), put them into the formula (ab)/(a-b), and return the answer to you." << endl;
	cout << endl;
	cout << fixed << showpoint;

	//input
	cout << "Please enter decimal number one: ";
	cin >> dblnum1;
	cout << endl;
	cout << "Please enter decimal number two: ";
	cin >> dblnum2;
	cout << endl;

	//calculation
	dblnum3 = (dblnum1 * dblnum2) / (dblnum1 - dblnum2);

	//output
	cout << "The answer is " << dblnum3 << endl;

    return 0;
}

