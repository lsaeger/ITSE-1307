#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	fltHeight = 0.0f;

	longGameKey = 0;
	fltDistanceCanRun = 0.0f;
}


Character::~Character()
{
}


std::string Character::getName()
{
	// TODO: Add your implementation code here.
	return std::string();
}


void Character::setName()
{
	// TODO: Add your implementation code here.
}


std::string Character::toString()
{
	// TODO: Add your implementation code here.
	return std::string();
}


bool Character::getMale()
{
	// TODO: Add your implementation code here.
	return false;
}


void Character::setMale()
{
	// TODO: Add your implementation code here.
}


bool Character::isPlayer()
{
	// TODO: Add your implementation code here.
	return false;
}


bool Character::isEnemy()
{
	// TODO: Add your implementation code here.
	return false;
}


bool Character::isNonPlayChar()
{
	// TODO: Add your implementation code here.
	return false;
}


float Character::getHeight()
{
	// TODO: Add your implementation code here.
	return 0.0f;
}


void Character::setHeight()
{
	// TODO: Add your implementation code here.
}


bool Character::isAbleToRun()
{
	// TODO: Add your implementation code here.
	return false;
}


void Character::toggleAblityToRun()
{
	// TODO: Add your implementation code here.
}


float Character::determineDistanceCharCanRun()
{
	// TODO: Add your implementation code here.
	return 0.0f;
}


int Character::equals()
{
	// TODO: Add your implementation code here.
	return 0;
}


bool Character::isAbleToTalk()
{
	// TODO: Add your implementation code here.
	return false;
}


void Character::setAbilityToTalk()
{
	// TODO: Add your implementation code here.
}


long Character::getGameKey()
{
	// TODO: Add your implementation code here.
	return 0;
}


void Character::setGameKey()
{
	// TODO: Add your implementation code here.
}


int Character::getUserPassCode()
{
	// TODO: Add your implementation code here.
	return 0;
}


void Character::setUserPassCode()
{
	// TODO: Add your implementation code here.
}


bool Character::compareGameKeyAndPassCode()
{
	// TODO: Add your implementation code here.
	return false;
}


void Character::setDistanceCanRun()
{
	// TODO: Add your implementation code here.
}


float Character::getDistanceCanRun()
{
	// TODO: Add your implementation code here.
	return 0.0f;
}
