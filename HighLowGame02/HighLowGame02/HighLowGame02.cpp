/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 03 24
Homework: High Low Game Improvements

Description: This program takes the program takes the High Low game
written by instructor Chris MacDougald and adds two
improvements. The original game allows the user to
guess a number between 1 and 100. The first improvement
allows the user to play again or exit the game.
The second improvement reports the number of
tries to the user not including invalid data. For
instance, a guess of 150 would not count as a try.
*/

/*
Improvement One
1. User plays game once.
2. Give user the option to play again or to quit.
	a. If user wants to play again, loop through the game again
	   until they are done playing.
	b. If user wants to quit, exit the game.
Improvement Two
1. Create a counter.
2. Count the number of tries.
3. Do not count tries if invalid data is entered.
4. Report the number of tries to the user when they guess the number.
*/

// Chris MacDougald
// ITSE 1307
// Simple High Low Guessing Game

/*
Pick a random number.
Have the user guess the number.
Display output based on users guess.
Repeat asking for users guess until it is equal to random number.
Display winning if user guessed random number.
*/

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int intLimit = 100; //Set limit for guess
	int intMinimum = 1; //Set minimum for guess
	int intGuess = 1;
	int intCurrentGuess = 1;
	int intCounter = 1;

	/*variable as a character instead of integer accounts for
	user entering invalid character data which will
	cause the program to crash when choosing to stay in game
	*/
	char charStayInGame = '1';

	do {//equal to StayInGame
		srand(time(NULL)); //Get random time

		//Give me a number between 0 and 51 then add 1.
		intGuess = rand() % intLimit + 1; 

//		cout << "Number to guess for debugging is: " <<  intGuess << endl;

		do { //Not equal to guess

			do { //User Input
				cout << "Please enter a number between 1 and " << intLimit;
				cout << ": ";
				cin >> intCurrentGuess;
			} while (intCurrentGuess < 1 || intCurrentGuess > intLimit);

			//want to add to counter but not if user guesses invalid number 
			if (intCurrentGuess > intGuess
				&& intCurrentGuess < (intLimit + 1)) {

				cout << "You guessed to high!" << endl;
				intCounter++;
			}

			//want to add to counter but not if user guesses invalid number
			else if (intCurrentGuess < intGuess
				&& intCounter >(intMinimum - 1)) {

				cout << "You guessed to low!" << endl;
				intCounter++;
			}
			else {
				//final output
				cout << "YOU GUESSED MY NUMBER!" << endl;

				//report of number of tries
				cout << "It took you " << intCounter;
				cout << (intCounter == 1 ? " try!" : " tries.");
				cout << endl;

				//user chooses to stay in game or exit
				cout << "   0: EXIT GAME" << endl;
				cout << "   1: PLAY AGAIN" << endl;
				cout << "Enter Choice: ";
				cin >> charStayInGame;
				cout << endl;

				switch (charStayInGame) {
				case ('0'):
					cout << "Thank you for playing!" << endl;
					break;
				case ('1'):
					cout << endl;
					break;
				default:
					cerr << "Invalid input. Exiting game.";
					cout << endl;
				}//end switch statement
			}//end else
		} while (intCurrentGuess != intGuess);
	} while (charStayInGame == '1');

	return 0;
}




