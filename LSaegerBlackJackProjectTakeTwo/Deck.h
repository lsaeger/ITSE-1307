
/*
Written by Christopher MacDougald

Used with permission by:
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 25

Description: This program includes the member variables and the
			 member function prototypes for the Deck class. 
*/

#pragma once

#include <vector>

#include <algorithm>

#include "Card.h"



class Deck

{

public:

	Deck();

	Deck(int intpNumberOfDecks);

	Deck(int intpNumberOfDecks, int intpShufflePoint);

	~Deck();

private:

	std::vector<Card> vtrDeck;

	int intShufflePoint = 0;

	int intCurrentCardIndex = 0;

	void init(int intpNumberOfDecks);

public:

	Card getCard();

	void shuffle();

	int size();

	int getShufflePercent();

	int getPercentOfDeckDealt();

	bool shouldShuffle();

	void setShufflePercent(int intpShufflePercent);

	Card getCard(int intpCurrentCardIndex);


};


