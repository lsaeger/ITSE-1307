#pragma once
#include <string>
class Character
{
private:
	std::string strName;
	bool boolIsMale;
	float fltHeight;
	bool boolAbleToRun;
	bool boolAbleToTalk;//non-playable chars may not talk
	int intPassCode;
	long longGameKey;//for game company to make sure user is supposed to be playig
	long getGameKey();//keeping methods private that have to do with key
	void setGameKey();
	bool compareGameKeyAndPassCode();

public:
	Character();
	~Character();
	std::string getName();
	void setName();
	bool getMale();
	void setMale();
	bool isPlayer();
	bool isEnemy();
	bool isNonPlayChar();
	float getHeight();
	void setHeight();
	bool isAbleToRun();
	void toggleAblityToRun();
	float determineDistanceCharCanRun();//would be based on other characteristics like isMale or isPlayer
	std::string toString();//standard to have a toString
	int equals();//some characters are reused and may want to see if you have made the same one
	bool isAbleToTalk();
	void setAbilityToTalk();
	int getUserPassCode();
	void setUserPassCode();

private:
	float fltDistanceCanRun;
public:
	void setDistanceCanRun();
	float getDistanceCanRun();
};

