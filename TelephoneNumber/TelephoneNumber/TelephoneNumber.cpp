/*
Lillian Saeger

ITSE 1307 Spring 2019

2019 03 05

Homework: Telephone Digits

Description: This program converts a mnemonic string into the actual
             phone number such as 800FLOWERS is 8003569377 and 
			 LAW4YOU is 5294968.
*/

/*
1. Ask user for mnemonic string input.

2. Read in string.

3. Make the letters in the string all lowercase.

4. Convert each letter character to the correct number.

5. Report the phone number back to the user.
*/

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;



int main()
{

	string strUserPhoneMnemonic = "TLRJDMW";

	int intCharacterCounter = 0;

	char chrCurrentLetter = 'a';


	//input
	cout << "This program will convert a phone number mnemonic";

	cout << " into the actual phone number." << endl;

	cout << "800FLOWERS is 8003569377 and law4you is 5294968.";

	cout << endl << endl;

	cout << "Enter a word to convert to a phone number ";

	cout << "without dashes, periods or parenthesis: ";

	cin >> strUserPhoneMnemonic;

	cout << endl;

	//output statement for "for loop" conversion output
	cout << "The phone number is: ";
	
	//processing of Mnemonic phone number to integers
	for (intCharacterCounter = 0;
		intCharacterCounter < strUserPhoneMnemonic.length();
		intCharacterCounter++) {

		//looking at current character in string
		chrCurrentLetter = strUserPhoneMnemonic.at(intCharacterCounter);

		//make chrCurrentLetter lowercase
		chrCurrentLetter = tolower(chrCurrentLetter);


		//switch statement with chrCurrentLetter variable
		switch (chrCurrentLetter) {
			case '1':
				cout << "1";
				break;
			
			case 'a':
			case 'b':
			case 'c':
			case '2':
				cout << "2";
				break;

			case 'd':
			case 'e':
			case 'f':
			case '3':
				cout << "3";
				break;

			case 'g':
			case 'h':
			case 'i':
			case '4':
				cout << "4";
				break;

			case 'j':
			case 'k':
			case 'l':
			case '5':
				cout << "5";
				break;

			case 'm':
			case 'n':
			case 'o':
			case '6':
				cout << "6";
				break;

			case 'p':
			case 'q':
			case 'r':
			case 's':
			case '7':
				cout << "7";
				break;

			case 't':
			case 'u':
			case 'v':
			case '8':
				cout << "8";
				break;

			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case '9':
				cout << "9";
				break;

			case '0':
				cout << "0";
				break;

			default:
				cerr << ", \"ERROR: Invalid Character \'" << chrCurrentLetter;
				cerr << "\'\", ";
			
		}//end switch statement

		
	}//end for loop

	cout << endl;

    return 0;
}

