/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 03 05
Homework: Telephone Digits
Description: This program converts a mnemonic string into the actual
			 phone number such as 800FLOWERS is 8003569377 and LAW4YOU
			 is 5294968.
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
#include <vector>

using namespace std;


int main()
{
	string strUserPhoneMnemonic = "TLRJDMW";
	int intCharacterCounter = 0;
	char chrCurrentLetter = 'a';
	vector<int> vtrCharacters;
	bool boolValid = true;//for processing valid data

	//input
	cout << "This program will convert a phone number mnemonic";
	cout << " into the actual phone number." << endl;
	cout << "800FLOWERS is 8003569377 and law4you is 5294968.";
	cout << endl << endl;
	cout << "Enter a mnemonic word for a phone number ";
	cout << "without dashes, periods or parenthesis: ";
	cin >> strUserPhoneMnemonic;
	cout << endl;

	//processing of characters from user string
	for (intCharacterCounter = 0;
		intCharacterCounter < strUserPhoneMnemonic.length();
		intCharacterCounter++) {

		//looking at current character in string
		chrCurrentLetter = strUserPhoneMnemonic.at(intCharacterCounter);

		//make current character lowercase
		chrCurrentLetter = tolower(chrCurrentLetter);

		//place integer that represents character into the vector
		switch (chrCurrentLetter) {
		case '1':
			vtrCharacters.push_back(1);
			break;
		case 'a':
		case 'b':
		case 'c':
		case '2':
			vtrCharacters.push_back(2);
			break;
		case 'd':
		case 'e':
		case 'f':
		case '3':
			vtrCharacters.push_back(3);
			break;
		case 'g':
		case 'h':
		case 'i':
		case '4':
			vtrCharacters.push_back(4);
			break;
		case 'j':
		case 'k':
		case 'l':
		case '5':
			vtrCharacters.push_back(5);
			break;
		case 'm':
		case 'n':
		case 'o':
		case '6':
			vtrCharacters.push_back(6);
			break;
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case '7':
			vtrCharacters.push_back(7);
			break;
		case 't':
		case 'u':
		case 'v':
		case '8':
			vtrCharacters.push_back(8);
			break;
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		case '9':
			vtrCharacters.push_back(9);
			break;
		case '0':
			vtrCharacters.push_back(0);
			break;
		default:
			cerr << ", \"Error: Invalid Character \'" << chrCurrentLetter ;
			cerr << "\'\",";
			boolValid = false;//flags invalid data
		}//end switch statement
	}//end for loop

	//Output
	if (boolValid) {//only valid data will be printed to screen
		cout << "The phone number is: ";

		for (int intNumberCounter = 0;
			intNumberCounter < vtrCharacters.size();
			intNumberCounter++) {

			cout << vtrCharacters.at(intNumberCounter);
		}
	}

	cout << endl;

	return 0;
}

