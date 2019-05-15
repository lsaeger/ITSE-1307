#pragma once
#include <string>
class Character
{
private:
	std::string strName;
	char charSexOrientation; //for variety of sexual orietations
	std::string strRace;
	int intHeight;
public:
	Character(); //for a default character for filling the background
	Character(std::string strpName, char charpSexOrientation, std::string strpRace, int intpHeight);
	~Character();
	std::string getName();
	void setName();
	char getSexOrientation();
	void setSexOrientation();
	std::string getRace();
	std::string setRace();
	std::string toString();
	int getHeight();
	void setHeight();
};

