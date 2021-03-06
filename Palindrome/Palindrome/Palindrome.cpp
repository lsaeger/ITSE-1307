/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 03 31
Description: This program is designed to take a string and determine
determine if it is a palindrome. For instance, madam is a palindrome
cloud is not.

puedocode:
1. Ase user for a string.
2. Use isPalindrome function to detrermine if the string is a 
   palindrome.
3. Return the result to the user.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string pstrUserString);

int main()
{
	string strUserString = "";
	bool bolPalindrome = false;

	//Palindrome test words as homework requests
	cout << "Testing some words to see if they are palindromes.";

	cout << endl;

	//User input
	cout << endl;
	cout << "Test to see if your word is a palindrome:";
	cout << endl;
	cout << "Enter the word you want to test: ";
	cin >> strUserString;
	cout << endl;

	//Processing: call isPalindrome and save value to boolean variable
	bolPalindrome = isPalindrome(strUserString);

	//Output 
	cout << strUserString;
	cout << (bolPalindrome ? " is a palindrome!" :
		     " is not a palindrome.");
	cout << endl;

    return 0;
}

//Checks to see if input string is a palindrome and returns a boolean
bool isPalindrome(string strpInputString) {
	int intlength = strpInputString.length();

	for (int intStringPosition = 0;
		intStringPosition < intlength / 2;
		intStringPosition++) {
		
		//added to function incase user typed Mom
		strpInputString[intStringPosition] = 
			tolower(strpInputString[intStringPosition]);

		if (strpInputString[intStringPosition]
			!= strpInputString[intlength - 1 - intStringPosition])
			return false;
	}
	return true;
}
