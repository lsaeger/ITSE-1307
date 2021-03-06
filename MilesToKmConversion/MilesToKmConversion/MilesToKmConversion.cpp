/*
Lillian Saeger
ITSE 1307 Spring 2019
20190212
This program asks users to input a distance in miles and converts that distance to kilometers.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const float MILES_TO_KM = 1.609f; //conversion factor for miles to kilometers

int main()
{
	int intMiles = 5;
	float fltKM = 10;

	//input
	cout << "Enter the distance travelled in miles: ";
	cin >> intMiles;
	cout << endl;

	//processing
	if (intMiles >= 0)
	{
		fltKM = intMiles * MILES_TO_KM;
		//output
		cout << fixed << setprecision(3) << "For a distance of " << intMiles << " miles the distance travelled in kilometers is: " << setw(10) << setfill('#') << fltKM << endl;
	}
	else
		cout << "Invalid input" << endl;
    return 0;
}

