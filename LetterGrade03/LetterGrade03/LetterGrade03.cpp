/**
* Lillian Saeger
* ITSE 2457
* March 18, 2019
* Quiz 5
* This program takes an integer grade or double grade and coverts it
*	to a Letter Grade such as A for 100 or B for 74.3.
*
* 1.  Ask user if they want to input an integer or a decimal number
* 2.  Take in input from 0 to 100 for an integer or
*		0.0 to 100.0 for a decimal 
* 3.  Convert decimal input to integer input 
* 4.  Convert the input to a grade such as A for 90 to 100
* 5.  Report grade back to user
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	char chrTypeOfGrade = 'i';
	char chrLetterGrade = 'D';
	int intGrade = 0;
	double dblGrade = 0.0;

	//Input to determine if user prefers integer or decimal grades
	cout << "This program lets you know what letter grade you have ";
	cout << "received based on a number grade between 0 and 100 ";
	cout << "inclusive." << endl << endl;
	cout << "Integer grades assign 0-59 F, 60-69 D, 70-79 C, ";
	cout << "80-89 B, and 90-100 A." << endl;
	cout << "Decimal grades round up and assign 0-59.49 F, ";
	cout << "59.50-69.49 D, 69.50-79.49 C, 79.50-89.49 B, and ";
	cout << "89.50-100 A." << endl << endl;
	cout << "Type I to enter your grade as an integer or D to enter";
	cout << " your grade as a decimal: ";
	cin >> chrTypeOfGrade;
	cout << endl;

	//change user input to lowercase to limit number of cases
	chrTypeOfGrade = tolower(chrTypeOfGrade);

	//Input of grade values
	if (chrTypeOfGrade == 'i') {
		//Input for integer grade
		cout << "Please enter grade received as an integer ";
		cout << "(0 - 100): ";
		cin >> intGrade;
		cout << endl;
	}
	else if (chrTypeOfGrade == 'd')	{
		//Input for decimal grade
		cout << "Please enter grade received as an decimal ";
		cout << "(0.00 - 100.00):  ";
		cin >> dblGrade;
		cout << endl;

		//rounding grade 
		dblGrade = round(dblGrade);
		/*casting grade to an integer since all dblgrade
		  will have been rounded to a whole number value
		*/
		intGrade = (int)dblGrade;
	}
	else {
		cerr << "Invalid input. Exiting program." << endl;
		return 1;
	}

	//Processing using if/else statements
	if (intGrade > 89) {
		chrLetterGrade = 'A';
	}
	else if (intGrade > 79)	{
		chrLetterGrade = 'B';
	}
	else if (intGrade > 69)	{
		chrLetterGrade = 'C';
	}
	else if (intGrade > 59)	{
		chrLetterGrade = 'D';
	}
	else {
		chrLetterGrade = 'F';
	}

	//Output of grade with if/else statements
	cout << "Your letter grade is: " << chrLetterGrade << endl;


	//Processing using a switch statement
	switch (intGrade / 10) {
		case 10:
		case 9:
			chrLetterGrade = 'A';
			break;
		case 8:
			chrLetterGrade = 'B';
			break;
		case 7:
			chrLetterGrade = 'C';
			break;
		case 6:
			chrLetterGrade = 'D';
			break;
		default:
			chrLetterGrade = 'F';
	}

	//Output of grade using a switch statement
	cout << "Your letter grade is: " << chrLetterGrade << endl;

    return 0;
}

