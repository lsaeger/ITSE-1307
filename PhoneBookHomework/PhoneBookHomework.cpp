// crmPhoneBook.cpp : This file contains the 'main' function. Program execution begins and ends there.

//

/*
Base program written by Christopher MacDougald

Modified with permission by:
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 26
Description: This program acts as a phone book collecting contacts
with an add function. It includes add contact, edit contact, 
delete contact, print contact(s), exterminate contacts, and 
quit the program

1. Have a menu for selecting what to do with the contact:
	add, edit, delete, print, exterminate, or quit the program.
2. Add: Add in first name, last name and phone number.
3. Edit: reset first name, last name and phone number fields,
4. Delete: Print out contacts. User chooses number of contact.
			Delete contact chosen.
5. Print: print out all of the contacts.
6. Exterminate: Clear all of the contacts.
7. Quit: Quit the program.
*/


#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include "Contact.h"
#include "PhoneBook.h"

//prints Menu selections
void printMenu() {
	std::cout << "Welcome to Phone Book" << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << "(a)dd a contact" << std::endl;
	std::cout << "(e)dit a contact" << std::endl;
	std::cout << "(d)elete a contact" << std::endl;
	std::cout << "(p)rint contacts" << std::endl;
	std::cout << "e(x)terminate all contacts" << std::endl;
	std::cout << "(q)uit" << std::endl;
}


//returns the integer index number of the contact
int getIndex(PhoneBook objpPhoneBook) {
	//prints contact list
	objpPhoneBook.printContacts();

	//creates local variable intIndex
	//when value is changed to 1 or greater, do..while loop will exit
	int intIndex = 0;

	do {
		std::cout << "Please enter the number next to the contact: ";
		std::cin >> intIndex;
	} while (intIndex <= 0);

	return intIndex;
}



int main()
{
	//create varibales
	char chrMenuChoice = ' ';
	int intContact = 0; //used for contact number vs. vector positon

	//create objects from classes
	PhoneBook objPhoneBook;
	Contact objContact;

	//executes menu
	do {
		printMenu();
		std::cin >> chrMenuChoice;

		//changes any user input to lower for switch logic
		chrMenuChoice = tolower(chrMenuChoice);

		switch (chrMenuChoice) {
		case 'a':
			//assign first name, last name, phone number strings to Contact 
			//obj member variables
			objContact.input();

			//adds the contact to the vector of Contacts objs
			objPhoneBook.addContact(objContact);

			break;
		case 'e':
			//returns the index of the contact user wants edited
			intContact = getIndex(objPhoneBook);

			//subtracts one to offset for vector positiond
			intContact--;

			//returns true if contact was edited
			objPhoneBook.editContact(intContact);
			break;
		case 'd':
			//returns the index of the contact user wants deleted
			intContact = getIndex(objPhoneBook);

			//subtracts one to offset for vector position
			intContact--;

			//returns true if contact was deleted
			objPhoneBook.deleteContact(intContact);
			break;
		case 'p':
			//prints list of Contact objects
			objPhoneBook.printContacts();
			break;
		case 'q':
			//TO NOTHING
			break;
		case 'x':
			//clears vector of Contact objects
			objPhoneBook.clearContacts();
			break;
		default:
			std::cerr << "Invalid Input";
			break;
		}//end switch
	} while (chrMenuChoice != 'q');
}//end main method