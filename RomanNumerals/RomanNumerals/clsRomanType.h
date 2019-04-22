#pragma once
#include <string>
#include <vector>

class clsRomanType
{
public:
	clsRomanType(double dblpUserDecimalNumber);
	clsRomanType(std::string strpUserRomanNumber);
	~clsRomanType();

private:
	double dblDecimalNumber;
	std::string strRomanNumber;
	std::vector<char> vtrRomanCharacters;

public:
	void setDecimalNumber(double dblpUserDecimalNumber);
	double getDecimalNumber();
	std::string convertDecimalToRomanNumeral();
	void printRomanNumeral();
	void printDecimalNumber();
	std::string getRomanNumber();
	void setRomanNumber(std::string strpRomanNumber);
	void initRomanNumber();
	void initDecimalNumber();
	void setRomanCharactersVector();
	bool verifyRomanNumberCharacters(char charpIndividualCharacter);
	bool verifyRomanNumberCharacters();
	double convertRomanNumberToDecimal();
	void convertOneRomanCharacter(int& intpSumOfCharacters, std::vector<char> vtrpRomanCharactersVector);
	void convertTwoRomanCharacters(int& intpSumOfCharacters, std::vector<char> vtrpRomanCharactersVector);
	bool isBiggerRomanNumber(std::vector<char> vtrpTempVector);
	std::vector<char> getRomanCharactersVector();
	std::string toString();
};

