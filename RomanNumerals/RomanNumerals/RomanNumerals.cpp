/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 21
Programming Roman Numerals

Description: This program converts a decimal number put in by the
user into a Roman Numeral. After the conversion, it will print 
the number as a decimal or Roman Numeral as requested by the
user.
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
	
	cout << fixed << showpoint << setprecision(2);

	/*
	cout << "Roman Numerals convert integers to numeric symbols for ";
	cout << "example XXV means 25." << endl;
	cout << "Enter a whole number between 1 and 3999 to convert it: ";
	cin >> dblUserDecimalNumber;
	cout << endl;

	clsRomanType objDecimalNumber = clsRomanType(dblUserDecimalNumber);
	strUserRomanNumber = objDecimalNumber.convertDecimalToRomanNumeral();
	cout << dblUserDecimalNumber << " is " << strUserRomanNumber << " as a Roman Numeral." << endl;

	objDecimalNumber.printRomanNumeral();
	cout << endl;

	cout << "Enter a Roman Numeral to convert it: ";
	cin >> strUserRomanNumber;
	cout << endl;

	clsRomanType objRomanNumber = clsRomanType(strUserRomanNumber);
	dblUserDecimalNumber = objRomanNumber.convertRomanNumberToDecimal();
	cout << dblUserDecimalNumber << " is " << strUserRomanNumber << " as a Roman Numeral." << endl;

	objRomanNumber.printDecimalNumber();
	cout << endl;
	*/





	while (boolStayInLoop) {
		cout << "Select W to enter a whole number to convert to a Roman Numeral" << endl;
		cout << "Select R to enter a Roman Numeral to convert to a whole number" << endl;
		cout << "Enter W or R: ";
		cin >> chrUserChar;
		chrUserChar = toupper(chrUserChar);
		cout << endl;

		if (chrUserChar == 'W') {
			cout << "Enter a whole number between 1 and 3999 to convert it: ";
			cin >> dblUserDecimalNumber;
			cout << endl;
			clsRomanType objDecimalNumber = clsRomanType(dblUserDecimalNumber);
			strUserRomanNumber = objDecimalNumber.convertDecimalToRomanNumeral();

			objDecimalNumber.printDecimalNumber();
			cout << " is " << objDecimalNumber.getRomanNumber() << " as a Roman Numeral." << endl;
			
			boolStayInLoop = false;
		}
		else if (chrUserChar == 'R') {
			cout << "Enter a Roman Numeral to convert it: ";
			cin >> strUserRomanNumber;
			cout << endl;
			clsRomanType objRomanNumber = clsRomanType(strUserRomanNumber);
			dblUserDecimalNumber = objRomanNumber.convertRomanNumberToDecimal();

			cout << objRomanNumber.getDecimalNumber() << " is ";
			objRomanNumber.printRomanNumeral();
			cout <<	" as a Roman Numeral." << endl;

			boolStayInLoop = false;
		}
	} 


    return 0;
}

