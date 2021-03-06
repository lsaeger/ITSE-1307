/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 03
Description: This program is designed to print out an asterisk tree 
with a height determined by the user.

Note: This program is based upon crmprinttree.cpp 
by Chris MacDougauld, the instructor for ITSE 1307.

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

void printTree(int intpHeight);

int main()
{
	int intUserTreeHeight = 5;

	//User input of height
	do {
		cout << "Enter 0 to EXIT or enter the height of the tree ";
		cout << "as an integer: ";
		cin >> intUserTreeHeight;
		cout << endl;

		//Outputs tree using User's height
		printTree(intUserTreeHeight);
	} while (intUserTreeHeight != 0);

    return 0;
}

//Outputs the blanks and *'s necessary to make a tree shape
void printTree(int intpHeight) {
	//Constructs tree
	int intAsterick = 1;//starts with one *
	for(int intRow = 1; intRow < intpHeight; intRow++){
		for (int intSpaces = 1;
			intSpaces <= intpHeight - intRow;
			intSpaces++) {
			cout << " ";
		}
		for (int intColumn = 1;
			intColumn <= intAsterick;
			intColumn++) {
			cout << "*";
		}
		intAsterick += 2;//adds two additional *'s per row
		cout << endl;
	}
	if (intpHeight > 0) {//doesn't print trunk ex: User enters 0 to EXIT
		//Prints trunk
		for (int intSpaces = 1;
			intSpaces < intpHeight;
			intSpaces++) {
			cout << " ";
		}
		cout << "*" << endl;
	}
}
