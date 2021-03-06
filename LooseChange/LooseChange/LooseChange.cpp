/*
Lillian Saeger
ITSE 1307 Spring 2019
20190212
This program is designed to calculate the amount of changed based on user input of
the number of pennies, nickels, dimes, quarters, and half-dollars entered. Used
the formula (.01 * numberOfPennies) + (.05 * numberOfNickels) + (.10 * numberOfDimes) + (.25 * numberOfQuarters) + (.50 * numberOfHalfDollars).
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

//listing of money values which will not change
const double PENNY_VALUE = 0.01;
const double NICKEL_VALUE = 0.05;
const double DIME_VALUE = 0.1;
const double QUARTER_VALUE = 0.25;
const double HALF_DOLLAR_VALUE = 0.50;

int main()
{
	int intNumPennies = 0;
	int intNumNickels = 0;
	int intNumDimes = 0;
	int intNumQuarters = 0;
	int intNumHalfDollars = 0;
	double dblTotalPennies = 0;
	double dblTotalNickels= 0;
	double dblTotalDimes = 0;
	double dblTotalQuarters = 0;
	double dblTotalHalfDollars = 0;
	double dblTotal = 0;


	cout << "This program will calculate how much your loose change is worth." << endl;
	cout << endl;
	cout << "You will be asked to enter the number of each type of coin separately." << endl;
	cout << endl;
	cout <<	"You will input the amount of pennies, nickels, dimes, quarters, and half-dollars." << endl;
	cout << endl;
	cout << "Enter an integer value for each type of coin." << endl;
	cout << endl;
	cout << "**********************************************************************************" << endl;

	//input
	cout << "Enter the number of pennies you have: ";
	cin >> intNumPennies;
	cout << endl;
	cout << "Enter the number of nickels you have: ";
	cin >> intNumNickels;
	cout << endl;
	cout << "Enter the number of dimes you have: ";
	cin >> intNumDimes;
	cout << endl;
	cout << "Enter the number of quarters you have: ";
	cin >> intNumQuarters;
	cout << endl;
	cout << "Enter the number of half-dollars you have: ";
	cin >> intNumHalfDollars;
	cout << endl;

	//calculations
	dblTotalPennies = PENNY_VALUE * intNumPennies;
	dblTotalNickels = NICKEL_VALUE * intNumNickels;
	dblTotalDimes = DIME_VALUE * intNumDimes;
	dblTotalQuarters = QUARTER_VALUE * intNumQuarters;
	dblTotalHalfDollars = HALF_DOLLAR_VALUE * intNumHalfDollars;
	dblTotal = dblTotalPennies + dblTotalNickels + dblTotalDimes + dblTotalQuarters + dblTotalHalfDollars;

	//output
	cout << fixed << setprecision(2);
	cout << "**********************************************************************************" << endl;
	cout << "Number of pennies: " << intNumPennies << endl;
	cout << "Number of nickels: " << intNumNickels << endl;
	cout << "Number of dimes: " << intNumDimes << endl;
	cout << "Number of quarters: " << intNumQuarters << endl;
	cout << "Number of half-dollars: " << intNumHalfDollars << endl;
	cout << endl;
	cout << "Your total is: $" << dblTotal << endl;

	return 0;
}

