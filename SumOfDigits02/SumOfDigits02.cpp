/*
Lillian Saeger

ITSE 1307 Spring 2019 

2019 03 24

Homework: Sum of the Digits

Description: This program takes an integer, adds up the digits and
			 returns the result back to the user.
*/

/*
1. Ask the user for an integer.

2. Separate the digits.

3. Sum up the digits.

4. Return the sum to the user.
*/

// SumOfDigits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	int intUserNumber = 0;

	int intNewNumber = 0; //processing variable

	int intRemainder = 0;

	int intSum = 0;


	//User input
	cout << "Enter an integer and the digits will be added up: ";

	cin >> intUserNumber;

	cout << endl;

	//assign user number to variable that allows it to be processed
	intNewNumber = intUserNumber;

	while (intNewNumber > 0) {//do not need to add in a final 0 digit

		if (intNewNumber < 10) {//process last digit (1-9)

			//add the last digit to the sum
			intSum = intSum + intNewNumber;

			//assign new value to the number so the loop will end
			intNewNumber = -1;

		}

		else {//process multidigit number

			//determine tens digit
			intRemainder = intNewNumber % 10;

			//remove tens digit to make new number
			intNewNumber = (intNewNumber - intRemainder) / 10;

			//add tens digit to the sum
			intSum += intRemainder;

		}

	}

	//output the sum to the user
	cout << "The sum of the numbers is: " << intSum << endl;

	return 0;

}//end main



