#pragma once

#include "Contact.h"

#include <string>

#include <vector>



class PhoneBook

{

public:

	PhoneBook();

	~PhoneBook();

	int addContact(Contact objContact);

	bool editContact(int intIndex);

	bool deleteContact(int intIndex);

	void printContacts();

	bool clearContacts();

private:

	std::vector<Contact> vtrPhoneBook;

};

