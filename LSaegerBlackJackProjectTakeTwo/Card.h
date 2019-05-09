/*
Written by Christopher MacDougald

Used with permission by:
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 25

Description: This program includes the member variables and the
			 member function prototypes for the Card class.
*/

#pragma once

#include <string>

#include <iostream>

#include <time.h>



class Card

{
public:

	Card();

	Card(int intpCard);

	~Card();

private:

	int intCard;

	int getValue();

public:

	void init(int intpCard);

	void setRandom();

	int getFaceValue();

	int getSuiteValue();

	std::string getSuiteString();

	std::string getFaceString();

	std::string toString();



};
