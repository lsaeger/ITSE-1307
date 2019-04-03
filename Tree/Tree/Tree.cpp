/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 03
Description: This program is designed to print out an asterisk tree 
with a height determined by the user.

1. Ask the user for the height of the tree.
2. Print out one *, making sure to center it using preceding blanks.
3. Every subsequent row print out two additional *'s makins sure to 
   center the row of *'s.
4. Except the final row, print out one * in the same position as 
   the * in row 1 to serve as the "trunk".
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void printTree(int intHeight);

int main()
{
	int intUserTreeHeight = 5;

	do {
		cout << "Enter the height of the tree as an integer: ";
		cin >> intUserTreeHeight;
		cout << endl;

		printTree(intUserTreeHeight);
	} while (intUserTreeHeight != 0);

    return 0;
}

void printTree(int intpHeight) {
	//Constructs tree
	int intWidth = 1;
	for(int intRow = 1; intRow < intpHeight; intRow++){
		for (int intSpaces = 1; intSpaces <= intpHeight - intRow; intSpaces++) {
			cout << " ";
		}
		for (int intColumn = 1; intColumn <= intWidth; intColumn++) {
			cout << "*";
		}
		intWidth += 2;
		cout << endl;
	}
	//Constructs "trunk"
	for (int intSpaces = 1; intSpaces, intpHeight; intSpaces++) {
		cout << " ";
	}
	cout << "*" << endl;
}