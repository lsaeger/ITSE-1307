#include "stdafx.h"
#include "clsRomanType.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

//constructor sets number to whole number 1 to 3999 per user input
clsRomanType::clsRomanType(double dblpUserDecimalNumber)
{
	setDecimalNumber(dblpUserDecimalNumber);
}

//constructor sets vector to the string of Roman Letter characters
clsRomanType::clsRomanType(std::string strpUserRomanNumber) {
	setRomanNumber(strpUserRomanNumber);
	setRomanCharactersVector();
}

clsRomanType::~clsRomanType()
{
}


void clsRomanType::setDecimalNumber(double dblpUserDecimalNumber)
{
	//allow user to re-enter number if outside of range
	if (dblpUserDecimalNumber < 1 || dblpUserDecimalNumber > 3999) {
		do {
			std::cout << "Enter a whole number between 1 and 3999:  ";
			std::cin >> dblpUserDecimalNumber;
			std::cout << std::endl;
		} while (dblpUserDecimalNumber < 1 
			     || dblpUserDecimalNumber > 3999);
	}
	else {
		//inside range: assign truncated input varibale decimal to class
		//variable decimal so it can be converted to a Roman Numeral
		dblDecimalNumber = trunc(dblpUserDecimalNumber);

		this->dblDecimalNumber = dblDecimalNumber;

	}

}

//returns decimal number variable
double clsRomanType::getDecimalNumber()
{
	return this->dblDecimalNumber;
}


void clsRomanType::initDecimalNumber()
{
	dblDecimalNumber = 0.0;
}

std::string clsRomanType::getRomanNumber()
{
	return (this->strRomanNumber);
}


void clsRomanType::setRomanNumber(std::string strpRomanNumber)
{
	//make string uppercase
	//https://stackoverflow.com/questions/735204
	std::transform(strpRomanNumber.begin(), strpRomanNumber.end(), strpRomanNumber.begin(), ::toupper);

	this->strRomanNumber = strpRomanNumber;
}

void clsRomanType::initRomanNumber()
{
	strRomanNumber.clear();
}

void clsRomanType::setRomanCharactersVector()
{
	for (int intVectorPosition = 0;
		intVectorPosition < (int)getRomanNumber().length();
		intVectorPosition++) {

		//make sure that it puts in an uppercase letter for the logic
		//put char at current position in string into same position in vector
		vtrRomanCharacters.push_back(toupper(getRomanNumber().at(intVectorPosition)));
	}

	//	this->vtrRomanCharacters = vtrRomanCharacters;
}

std::vector<char> clsRomanType::getRomanCharactersVector()
{

	return (this->vtrRomanCharacters);
}

bool clsRomanType::verifyRomanNumberCharacters(char charpIndividualCharacter)
{
	charpIndividualCharacter = toupper(charpIndividualCharacter);

	if (charpIndividualCharacter == 'I' ||
		charpIndividualCharacter == 'V' ||
		charpIndividualCharacter == 'X' ||
		charpIndividualCharacter == 'L' ||
		charpIndividualCharacter == 'C' ||
		charpIndividualCharacter == 'D' ||
		charpIndividualCharacter == 'M') {
		return true;
	}
	else {
		//will not let me do this...says cerr does not exist
		//		std::cerr << "clsRomanType::verifyRomanNumber: Warning only I, V, X, L, C, D, M are allowed as Roman Numerals" << std::endl;
		return false;
	}
	return 0;
}

bool clsRomanType::verifyRomanNumberCharacters()
{
	int intCounter = 0;

	for (int intVectorPosition = 0;
		intVectorPosition < (int)getRomanCharactersVector().size();
		intVectorPosition++) {

		switch (getRomanCharactersVector().at(intVectorPosition)) {
		case 'i':
		case 'v':
		case 'x':
		case 'l':
		case 'c':
		case 'd':
		case 'm':
		case 'I':
		case 'V':
		case 'X':
		case 'L':
		case 'C':
		case 'D':
		case 'M':
			break;
		default:
			intCounter++;
		}
	}

	if (intCounter == 0) {
		return true;
	}
	else {
		//will not let me do this...says cerr does not exist
		//		std::cerr << "clsRomanType::verifyRomanNumber: Warning only I, V, X, L, C, D, M are allowed as Roman Numerals" << std::endl;
		return false;
	}

}

double clsRomanType::convertRomanNumberToDecimal()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	int intSumOfCharacters = 0;
	std::vector<char> tempVector = getRomanCharactersVector();

	do {
		if (tempVector.size() == 1) {
			convertOneRomanCharacter(intSumOfCharacters, tempVector);
			tempVector.erase(tempVector.begin() + 0);   //get rid of last element so that the loop will end
		}
		else {//number in first position must be equal or larger than number in second position
			if (tempVector.at(0) == tempVector.at(1)
				|| isBiggerRomanNumber(tempVector)) {
				convertOneRomanCharacter(intSumOfCharacters, tempVector);
				tempVector.erase(tempVector.begin() + 0);//get rid of first element
			}
			else {
				convertTwoRomanCharacters(intSumOfCharacters, tempVector);//when first position is smaller than second position, the two characters represent 4, 9, 40, 90, 400, or 900 only
				tempVector.erase(tempVector.begin(), tempVector.begin() + 2);//get rid of first two elements in vector
			}
		}
	} while (tempVector.size() > 0);

	dblDecimalNumber = (double)intSumOfCharacters;

	//debug line
	//std::cout << "This is the final sum !!!!!!!!!!!!!: " << dblDecimalNumber << std::endl;

	setDecimalNumber(dblDecimalNumber);

	return dblDecimalNumber;
}

void clsRomanType::convertOneRomanCharacter(int& intpSumOfCharacters, std::vector<char> vtrpRomanCharactersVector)
{
	std::vector<char> tempVector = vtrpRomanCharactersVector;

	switch (tempVector.front()) {
	case 'I':
		intpSumOfCharacters += 1;
		break;
	case 'V':
		intpSumOfCharacters += 5;
		break;
	case 'X':
		intpSumOfCharacters += 10;
		break;
	case 'L':
		intpSumOfCharacters += 50;
		break;
	case 'C':
		intpSumOfCharacters += 100;
		break;
	case 'D':
		intpSumOfCharacters += 500;
		break;
	case 'M':
		intpSumOfCharacters += 1000;
	}
}

void clsRomanType::convertTwoRomanCharacters(int& intpSumOfCharacters, std::vector<char> vtrpRomanCharactersVector)
{
	std::vector<char> tempVector = vtrpRomanCharactersVector;

	if (tempVector.at(0) == 'I') {
		switch (tempVector.at(1)) {
		case 'V':
			intpSumOfCharacters += 4;
			break;
		case 'X':
			intpSumOfCharacters += 9;
		}
	}
	else if (tempVector.at(0) == 'X') {
		switch (tempVector.at(1)) {
		case 'L':
			intpSumOfCharacters += 40;
			break;
		case 'C':
			intpSumOfCharacters += 90;
		}

	}
	else if (tempVector.at(0) == 'C') {
		switch (tempVector.at(1)) {
		case 'D':
			intpSumOfCharacters += 400;
			break;
		case 'M':
			intpSumOfCharacters += 900;
		}
	}

}




//compares left to right and asks if left element is Bigger
bool clsRomanType::isBiggerRomanNumber(std::vector<char> vtrpTempVector)
{
	bool boolReturn = false;
	std::vector<char> tempVector = vtrpTempVector;

	switch (tempVector.at(0)) {
	case 'M':
		switch (tempVector.at(1)) {
		case 'D':
		case 'C':
		case 'L':
		case 'X':
		case 'V':
		case 'I':
			boolReturn = true;
			break;
		}
		break;
	case 'D':
		switch (tempVector.at(1)) {
		case 'C':
		case 'L':
		case 'X':
		case 'V':
		case 'I':
			boolReturn = true;
			break;
		}
		break;
	case 'C':
		switch (tempVector.at(1)) {
		case 'L':
		case 'X':
		case 'V':
		case 'I':
			boolReturn = true;
			break;
		}
		break;
	case 'L':
		switch (tempVector.at(1)) {
		case 'X':
		case 'V':
		case 'I':
			boolReturn = true;
			break;
		}
		break;
	case 'X':
		switch (tempVector.at(1)) {
		case 'V':
		case 'I':
			boolReturn = true;
			break;
		}
		break;
	case 'V':
	{
		if (tempVector.at(1) == 'I')
			boolReturn = true;
		break;
	}
	}

	return boolReturn;
}







std::string clsRomanType::toString()
{
	std::string strOutput = "{";
	strOutput += "Roman Number: ";
	strOutput += getRomanNumber();
	strOutput += "}";
	return strOutput;
}




std::string clsRomanType::convertDecimalToRomanNumeral()
{
	int intNumberToConvert = (int)getDecimalNumber();
	int intNumberInDecimalPlace = 0;
    std::string strConvertedRomanNumeral = "";

//debug  	std::cout << "This is what I need to convert: " << intNumberToConvert << std::endl;
	if (intNumberToConvert > 999) {

		//determines the number in the 1000's place
		intNumberInDecimalPlace = intNumberToConvert - (intNumberToConvert % 1000);

		switch (intNumberInDecimalPlace/1000) {
			case 1:
				strConvertedRomanNumeral += "M";
				break;
			case 2:
				strConvertedRomanNumeral += "M";
				break;
			case 3:
				strConvertedRomanNumeral += "MMM";
				break;
			default:
				std::cerr << "Standard Digits only up to 3 for thousands place" << std::endl;
		}

		//getting rid of the 1000's place
		intNumberToConvert = intNumberToConvert % 1000;
	}

	


	if (intNumberToConvert > 99) {// hundred's

		//determines the number in the 100's place
		intNumberInDecimalPlace = intNumberToConvert - intNumberToConvert % 100;

		switch (intNumberInDecimalPlace/100) {
			case 0:
				break;
			case 1:
				strConvertedRomanNumeral += "C";
				break;
			case 2:
				strConvertedRomanNumeral += "CC";
				break;
			case 3:
				strConvertedRomanNumeral += "CCC";
				break;
			case 4:
				strConvertedRomanNumeral += "CD";
				break;
			case 5:
				strConvertedRomanNumeral += "D";
				break;
			case 6:
				strConvertedRomanNumeral += "DC";
				break;
			case 7:
				strConvertedRomanNumeral += "DCC";
				break;
			case 8:
				strConvertedRomanNumeral += "DCCC";
				break;
			case 9:
				strConvertedRomanNumeral += "CM";
				break;
			default:
				std::cerr << "Standard Digits only 0-9 for hundreds place" << std::endl;
		}
		
		//getting rid of the 100's place
		intNumberToConvert = intNumberToConvert % 100;
	}

	
	

	if (intNumberToConvert > 9) {//ten's
		//determines the number that was in the 10's place
		intNumberInDecimalPlace = intNumberToConvert - ( intNumberToConvert % 10);

		switch (intNumberInDecimalPlace/10) {
			case 0:
				break;
			case 1:
				strConvertedRomanNumeral += "X";
				break;
			case 2:
				strConvertedRomanNumeral += "XX";
				break;
			case 3:
				strConvertedRomanNumeral += "XXX";
				break;
			case 4:
				strConvertedRomanNumeral += "XL";
				break;
			case 5:
				strConvertedRomanNumeral += "L";
				break;
			case 6:
				strConvertedRomanNumeral += "LX";
				break;
			case 7:
				strConvertedRomanNumeral += "LXX";
				break;
			case 8:
				strConvertedRomanNumeral += "LXXX";
				break;
			case 9:
				strConvertedRomanNumeral += "XC";
				break;
			default:
				std::cerr << "Standard Digits only 0-9 for tens place" << std::endl;
		}
		
		//getting rid of the 10's place
//		intNumberToConvert = intNumberToConvert % 10;

	}


	
	//determines number in 1's decimal place
	intNumberInDecimalPlace = intNumberToConvert % 10;
	
	switch (intNumberInDecimalPlace) {//one's
		case 0:
			break;
		case 1:
			strConvertedRomanNumeral += "I";
			break;
		case 2:
			strConvertedRomanNumeral += "II";
			break;
		case 3:
			strConvertedRomanNumeral += "III";
			break;
		case 4:
			strConvertedRomanNumeral += "IV";
			break;
		case 5:
			strConvertedRomanNumeral += "V";
			break;
		case 6:
			strConvertedRomanNumeral += "VI";
			break;
		case 7:
			strConvertedRomanNumeral += "VII";
			break;
		case 8:
			strConvertedRomanNumeral += "VIII";
			break;
		case 9:
			strConvertedRomanNumeral += "IX";
			break;
		default:
			std::cerr << "Standard Digits only 0-9 for ones place" << std::endl;
	}

	setRomanNumber(strConvertedRomanNumeral);
	return strConvertedRomanNumeral;
}


void clsRomanType:: printRomanNumeral()
{
	std::cout << getRomanNumber();
}


void clsRomanType::printDecimalNumber()
{
	std::cout << getDecimalNumber();
}
