/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 21
Programming Roman Numerals

Description: This program converts a decimal number put in by the
user into a Roman Numeral. After the conversion, it will print
the number as a decimal or Roman Numeral as requested by the
user.

1. Ask the user to chose to convert a Roman Number or a whole number.
2. For Roman Number 
	a. Take in the Roman Numeral string
	b. Make the RomanType object inputting the string which will use
		the constuctor that will set the string and a vector based 
		on that string.
	c. Use the vector to verify the input had the correct Roman
	   letters.
	d. Make sure the letters are uppercase.
	e. Go through the vector and add or subtract the combination
	   of characters based on looking at two letters at a time.
	   (if there is one letter, just add that value).
	f. Convert the sum to a decimal.
	g. Return the final value as a decimal.
3. For Decimal Number
	a. Take in the Decimal number
	b. m
	Make the RomanType object by inputting the decimal
		which will use th constructor that will set the
		decimal value.
	c. If the value is less than 1 or more than 3999
	   ask for another input.
	d. If the value is 1 to 3999 truncate the double
	   value and set to an intger value.
	e. Convert the integer value to a Roman Number
	   based on place value.
	f. Return the Roman Numeral string.
4. Return the converted value to the user and print
   both the inputted value and the converted value.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "clsRomanType.h"


using namespace std;

int main()
{
	double dblUserDecimalNumber = 1;
	string strUserRomanNumber = "";
	char chrUserChar = 'W';
	bool boolStayInLoop = true;

	//double will be in the form 25.00
	cout << fixed << showpoint << setprecision(2);
	
	cout << "Roman Numerals are symbolic representations of numbers ";
	cout << "such as XXV for 25. " << endl;
	cout << endl;

	//input
	while (boolStayInLoop) {
		cout << "Select W to convert a whole number to a Roman ";
		cout << "Numeral" << endl;
		cout << "Select R to convert a Roman Numeral to a whole ";
		cout << "number" << endl;
		cout << "Enter W or R: ";
		cin >> chrUserChar;
		chrUserChar = toupper(chrUserChar);
		cout << endl;

		if (chrUserChar == 'W') {
			cout << "Enter a whole number between 1 and 3999 to ";
			cout << "convert it: ";
			cin >> dblUserDecimalNumber;
			cout << endl;

			//create object for Decimal conversion
			clsRomanType objDecimalNumber = 
				clsRomanType(dblUserDecimalNumber);

			strUserRomanNumber =
				objDecimalNumber.convertDecimalToRomanNumeral();

			objDecimalNumber.printDecimalNumber();
			cout << " is ";
			cout << objDecimalNumber.getRomanNumber();
			cout << " as a Roman Numeral." << endl;

			boolStayInLoop = false;
		}
		else if (chrUserChar == 'R') {
			cout << "Enter a Roman Numeral to convert it: ";
			cin >> strUserRomanNumber;
			cout << endl;

			//create object for Roman Number conversion
			clsRomanType objRomanNumber = 
				clsRomanType(strUserRomanNumber);

			dblUserDecimalNumber = 
				objRomanNumber.convertRomanNumberToDecimal();

			cout << objRomanNumber.getDecimalNumber() << " is ";
			objRomanNumber.printRomanNumeral();
			cout << " as a Roman Numeral." << endl;

			boolStayInLoop = false;
		}
	}
	
	



	return 0;
}


