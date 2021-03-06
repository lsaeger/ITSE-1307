// LSaegerFinalQuestion29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;


int main()
{
	//randomize by time
	srand(time(NULL));

	//create variables
	int intDieOne = rand() % 6 + 1;
	int intDieTwo = rand() % 6 + 1;

	//print out Die values that have been chosen randomly
	cout << "Die one: " << intDieOne << endl;
	cout << "Die two: " << intDieTwo << endl;

	//logic for determining if die values are in special categories
	if (intDieOne == 1 && intDieTwo == 1) {
		cout << "Snake Eyes" << endl;
	}
	else if (intDieOne == 2 && intDieTwo == 2) {
		cout << "Hard Four" << endl;
	}
	else if ((intDieOne == 3 && intDieTwo == 4) ||
		(intDieOne == 4 && intDieTwo == 3) ||
		(intDieOne == 2 && intDieTwo == 5) ||
		(intDieOne == 5 && intDieTwo == 2) ||
		(intDieOne == 1 && intDieTwo == 6) ||
		(intDieOne == 6 && intDieTwo == 1)) {
		cout << "Seven out" << endl;
	}
	else if ((intDieOne == 5 && intDieTwo == 6) ||
		(intDieOne == 6 && intDieTwo == 5)) {
		cout << "Yo-leven" << endl;
	}
	else if (intDieOne == 6 && intDieTwo == 6) {
		cout << "Midnight" << endl;
	}
	else {
		cout << "Nothing Here" << endl;
	}

    return 0;
}

