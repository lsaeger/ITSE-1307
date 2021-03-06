/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 03 31 
Description: This program is design to take a character from the
user and determine if the character is a vowel.

1. Ask the user for a character.
2. Determine if the character is a vowel.
3. Tell the user if the character is a vowel.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

bool isVowel(char pchrUserCharacter);

int main()
{
	char chrUserCharacter = 'a';
	bool bolVowel = false;

	//User input
	cout << "Enter a letter to see if it is a vowel: ";
	cin >> chrUserCharacter;
	cout << endl;

	//Processing of character using isVowel function
	bolVowel = isVowel(chrUserCharacter);

	//Output to user
	cout << chrUserCharacter;
	cout << (bolVowel ? " is a vowel." 
		     : " is not a vowel.");
	cout << endl;

    return 0;
}

//Takes in a character and returns a boolean of true if the character
//is a vowel and false is the character is not a vowel
bool isVowel(char pchrUserCharacter) {
	//make character lowercase 
	pchrUserCharacter = tolower(pchrUserCharacter);

	switch (pchrUserCharacter){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	}
	return false;
}

