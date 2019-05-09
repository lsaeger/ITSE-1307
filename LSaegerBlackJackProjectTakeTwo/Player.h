/*
Written by Christopher MacDougald

Used with permission by:
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 25

Description: This program includes the member variables and the
			 member function prototypes for the Player class.
*/

#pragma once

#include <string>

#include <vector>

#include "Card.h"



class Player

{

public:

	Player();

	~Player();

private:

	int intPlayerNumber;

	int intMoney;

	int intBet;

	std::string strName;

	std::vector<Card> vtrPlayerHand;

	void setPlayerNumber();

public:

	std::string inputPlayerName();

	void setPlayerName(std::string strpName);

	int getHandPointValue();

	void printHand();

	std::string toString();

	std::string getHandString();

	std::string getPlayerName();

	bool addCard(Card objpCard);

	int getNumberCards();

	void clearHand();



	void setMoney(int intpMoney);

	int getMoney();

	void setBet(int intpBet);

	int getBet();

	int inputPlayerBet();







};
