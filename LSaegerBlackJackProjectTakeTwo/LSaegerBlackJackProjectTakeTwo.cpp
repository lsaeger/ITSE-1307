/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 04 25

Description: This program is designed to run a Blackjack-like game.
Four standard 52 card decks are used to play. There is a dealer and
a minimum of 2 players. Players are given a maximum of 5 cards.
Each player and the Dealer is given 1000 initial betting money.
No player can bet more than the 1000. If a player runs out of money 
they can no longer play. If the Dealer runs out of money or all
of the player run out of money, all play ends. There must be two
players to continue between rounds. The initial menu includes three 
levels options for levels of play difficulty.

Initial Setup:
1. Present initial menu with option to start new game, chose level
   of difficulty, or quit.
2. If the player quits...quit the game
3. If the player wants to choose difficulty, change the shuffle deck
   percentage then continue with game play as normal.
4. If player chose new game or if the player chose the game with a 
   difficulty level the game will be played in the same manner as 
   follows:

Game Play:
1. Get names of players.
2. Give players initial bid money.
3. Give first two cards and look for BLACKJACK.
	Dealer BLACKJACK ends the round. Player BLACKJACK awards money.
4. Players bid. Dealer bid is set at an amount of 5.
5. Give players an opportunity to take more cards up to 5 cards.
	Hand values over 21 are bust and player's round is finished.
6. Dealer takes cards last based on a hand value less than 16 and
	if they have no more than 5 cards. Dealer bust ends round and
	pays out to players.
7. Award money if the Dealer hand is less than the player hand
    and the player is not over 21. Players who have zero money
    cannot continue.
8. Shuffle cards between rounds if the cards are 75% gone. If
	difficulty levels were chosen, shuffle cards at appropriate
	percentage. If Dealer has no money, the game cannot continue
	and the player with the most money wins.
9. Ask the group of players if they want to play another round or
    quit the game.

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "ListOfPlayers.h"

using namespace std;

char Menu();

int getNumPlayers();

void callWinner(
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer, 
	int intpNumberOfPlayer);

void dealFirstTwoCardsToAll(
	int& intpNumberOfPlayers, 
	Player& objpDealer, 
	vector<Player>& vtrpObjPlayer, 
	Deck& objpDeck);

void dealPlayerCardsThreeToFive(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer, 
	Deck& objpDeck, 
	Player& objpDealer);

void dealDealerCardsThreeToFive(
	Player& objpDealer, 
	Deck& objpDeck, 
	vector<Player>& vtrpObjPlayer, 
	int& intpNumberOfPlayers);

void shuffleDeck(Deck& objpDeck);

void clearPlayerHands(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer);

void placeYourBets(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer);

void setPlayerNames(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer);

void addPlayerWinningsSubtractDealerLosses(
	int intpPosition, 
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer);

void subtractPlayerLossesAddDealerWinnings(
	int intpPosition, 
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer);

void winnerDeterminedByMoney(
	int& intpNumberOfPlayers, 
	vector<Player> vtrpObjPlayer);

int determineCombinedPlayerMoney(
	int& intpNumberOfPlayers,
	vector<Player>& vtrpObjPlayer);

void deletePlayersWithNoMoney(
	int& intpNumberOfPlayers,
	vector<Player>& vtrpObjPlayer);

bool playRoundAgain(
	int& intpNumberOfPlayers,
	vector<Player>& vtrpObjPlayer,
	Player& objpDealer);

int main()
{
	int intNumberOfPlayers = 2;
	char charMenuChoice = 'N';
	bool boolPlayRoundAgain = true;
	int intShufflePercent = 75;

	do{
		charMenuChoice = Menu();

		//user wants to choose difficulty level
		if (charMenuChoice == 'D') {
			charMenuChoice = 'N'; //so that a new game will start
			char charDifficultyLevel = 'A';
		
			cout << endl;
			cout << "   CHOOSE YOUR LEVEL OF DIFFICULTY" << endl;
			cout << "(A)mateur  (C)hallenging   (E)xpert : ";
			cin >> charDifficultyLevel;
			charDifficultyLevel = toupper(charDifficultyLevel);
			switch (charDifficultyLevel) {
				case 'C':
					intShufflePercent = 50;
				case 'E':
					intShufflePercent = 25;
				default://defaut to amateuter level
					intShufflePercent = 75;
			}
		}
	
		if (charMenuChoice == 'N') {
			//allows the cards to be chosen randomly
			srand((int)time(NULL));

			//creates player object for Dealer and set name and bet
			Player objDealer;
			objDealer.setPlayerName("Dealer");
			objDealer.setBet(10);

			//creates decks object initialized to 4 decks
			Deck objDeck = Deck(4);

			//determine number of players
			intNumberOfPlayers = getNumPlayers();

			//vector of player objects...
			//must stay here bec needs intNumberOfPlayers
			vector<Player> vtrObjPlayer(intNumberOfPlayers);

			//store player names
			setPlayerNames(intNumberOfPlayers, vtrObjPlayer);

			//based on difficulty level chosen by user
			objDeck.setShufflePercent(intShufflePercent);

			//shuffles the deck
			objDeck.shuffle();

			vector<bool> vtrHasMoney(
				intNumberOfPlayers, true);
				
			do {

				placeYourBets(intNumberOfPlayers,
					vtrObjPlayer,
					objDealer);

				dealFirstTwoCardsToAll(intNumberOfPlayers,
					objDealer,
					vtrObjPlayer,
					objDeck);

				dealPlayerCardsThreeToFive(intNumberOfPlayers,
					vtrObjPlayer,
					objDeck,
					objDealer);

				dealDealerCardsThreeToFive(objDealer,
					objDeck,
					vtrObjPlayer,
					intNumberOfPlayers);

				callWinner(vtrObjPlayer,
					objDealer,
					intNumberOfPlayers);

				shuffleDeck(objDeck);

				objDealer.clearHand();

				clearPlayerHands(intNumberOfPlayers, 
					vtrObjPlayer);

				boolPlayRoundAgain = playRoundAgain(intNumberOfPlayers,
										vtrObjPlayer,
										objDealer);
			} while (boolPlayRoundAgain == true);
		}//end if charMenuChoice
	}while (charMenuChoice != 'Q');//end while charMenuChoice

	return 0;
}// end main function

int getNumPlayers() {
	int intNumberOfPlayers = 0;

	do {
		cout << "Minimum number of players is 2. " << endl;
		cout << "Enter the number of players: ";
		cin >> intNumberOfPlayers;
	} while (intNumberOfPlayers < 2);

	return intNumberOfPlayers;
}//end getNumPlayers function


void callWinner(vector<Player>& vtrpObPlyr, 
	Player& objpDealer, 
	int intpNumberOfPlayers) {

	//debug
	//cout << "Dealer Money is: " << objpDealer.getMoney() << endl;

	for (int intPlyrCnt = 0; 
		intPlyrCnt < intpNumberOfPlayers;
		intPlyrCnt++) {
					
		if ((objpDealer.getHandPointValue() < 
		vtrpObPlyr.at(intPlyrCnt).getHandPointValue() &&
		vtrpObPlyr.at(intPlyrCnt).getHandPointValue() <= 21) ||
		(objpDealer.getHandPointValue() > 21 &&
		vtrpObPlyr.at(intPlyrCnt).getHandPointValue() <= 21)) {

			cout << vtrpObPlyr.at(intPlyrCnt).getPlayerName();
			cout <<	" has ";
			cout << vtrpObPlyr.at(intPlyrCnt).
				getHandPointValue();
			cout << " while ";
			cout << objpDealer.getPlayerName();
			cout << " has ";
			cout << objpDealer.getHandPointValue() << endl;
			cout << vtrpObPlyr.at(intPlyrCnt).getPlayerName();
			cout << " beat dealer!";
			cout << endl;
			addPlayerWinningsSubtractDealerLosses(
				intPlyrCnt, 
				vtrpObPlyr, 
				objpDealer);

			cout << endl;
		}
		else {
			subtractPlayerLossesAddDealerWinnings(
				intPlyrCnt, 
				vtrpObPlyr, 
				objpDealer);
		}
	}

	//debug
	//cout << "Dealer bet: " << objpDealer.getBet() << endl;
	//cout << "Dealer Money is: " << objpDealer.getMoney() << endl;

}//end callWinner function


void dealFirstTwoCardsToAll(
	int& intpNumberOfPlayers,
	Player& objpDealer,
	vector<Player>& vtrpObjPlayer,
	Deck& objpDeck){
	for (int intFirstTwoCards = 1; 
		intFirstTwoCards <= 2; 
		intFirstTwoCards++) {//gives out first two cards

		for (int intPlayerCount = 0; 
			intPlayerCount < intpNumberOfPlayers; 
			intPlayerCount++) {//gives card to the players

			vtrpObjPlayer.at(intPlayerCount).
				addCard(objpDeck.getCard());

			//lists Player name, hand value, list of cards 
			//in hand (ex: 10 of Spades, 2 of Diamonds)
			cout << vtrpObjPlayer.at(intPlayerCount).toString();
			cout << endl;
		
			if (vtrpObjPlayer.at(intPlayerCount).getHandPointValue() 
				== 21) {
				
				cout << vtrpObjPlayer.at(intPlayerCount).
					getPlayerName() << ": BLACKJACK$$$$$";
				cout << endl;
			}
		}//end player for loop giving out first two card

		//gives card to dealer
		objpDealer.addCard(objpDeck.getCard());
		//Dealer name, hand, cards in hand 
		//(ex: 10 of Spades, 2 of Diamonds)
		cout << objpDealer.toString() << endl;
	}
}// end of dealFirstTwoCardsToAll function


void dealPlayerCardsThreeToFive(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer, 
	Deck& objpDeck, 
	Player& objpDealer) {
	
	char chrOneMoreCard = 'Y';
	
		for (int intPlayerCount = 0; 
			intPlayerCount < intpNumberOfPlayers; 
			intPlayerCount++) {

			//so the next person will be asked for a card even 
			//if the person before is done getting cards
			chrOneMoreCard = 'Y';

			while (chrOneMoreCard == 'Y' && 
				vtrpObjPlayer.at(intPlayerCount).
				getHandPointValue() != 21) {

				if (vtrpObjPlayer.at(intPlayerCount).
					getNumberCards() < 5) {

					//asking current player if the would like a 
					//card and adding it to their hand if they 
					//have fewer than 5 cards
					cout << endl;
					cout << vtrpObjPlayer.at(intPlayerCount).
						getPlayerName() <<
						" would you like another card?";
					cout << endl;
					cout << "Player stats: " <<
						vtrpObjPlayer.at(intPlayerCount).toString();
					cout << endl;
					cout << "Select (H)it or (S)tay: ";
					cin >> chrOneMoreCard;
					chrOneMoreCard = toupper(chrOneMoreCard);
					cout << endl;

					//gives card and displays card details
					if (chrOneMoreCard == 'H') {
						vtrpObjPlayer.at(intPlayerCount).
							addCard(objpDeck.getCard());
						cout << vtrpObjPlayer.at(intPlayerCount).
							toString() << endl;
						chrOneMoreCard = 'Y';

						//tells player they busted
						if (vtrpObjPlayer.at(intPlayerCount).
							getHandPointValue() > 21) {

							cout << vtrpObjPlayer.at(intPlayerCount).
								getPlayerName();
							cout << " has busted!" << endl;
							cout << endl;
							chrOneMoreCard = 'N';
						}
					}
					else {
						chrOneMoreCard = 'N';
					}
				}
				else {
					chrOneMoreCard = 'N';
				}
			}//end while
		}//end for loop with intPlayerCount

}//end dealPlayerCardThreeToFive function



void dealDealerCardsThreeToFive(
	Player& objpDealer, 
	Deck& objpDeck, 
	vector<Player>& vtrpObjPlayer, 
	int& intpNumberOfPlayers) {

	//if dealer got blackjack will not print out
	cout << "Checking - Dealer taking anymore cards?..." << endl;
	
	//Dealer gets another card if their total point value 
	//is less than 16
	while (objpDealer.getHandPointValue() <= 16 &&
		objpDealer.getNumberCards() < 5) {

		//gives the Dealer another card and displays card
		objpDealer.addCard(objpDeck.getCard());
		cout << objpDealer.toString() << endl;
	}

	cout << "Dealer is done taking cards.";
	cout << endl;
	cout << objpDealer.toString() << endl;
	cout << endl << endl;

}//end funtion dealDealerCardThreeToFive function


void shuffleDeck(Deck& objpDeck) {
	
	//if the decks reach 75% card given out, shuffle the deck
	//unless difficulty level is set to shuffle more often
	if (objpDeck.shouldShuffle()) {
		objpDeck.shuffle();
	}
}//end shuffleDeck function


char Menu(){
	char chrAnswer = 'N';
	
	//welcome menu
	cout << "$$$$$$$$$$  Welcome to BLACKJACK  $$$$$$$$$$";
	cout <<	endl << endl;
	cout << "             Winner pays 2 to 1." << endl;
	cout << "        All ties favor the Dealer." << endl;
	cout << "         Whole dollar bets only. " << endl; 
	cout << "Bets cannot exceed your current Money holdings.";
	cout << endl << endl;
	cout << "(N)ew Game...";
	cout << "(D)ifficulty Level...";
	cout <<  "(Q)uit" << endl;
	cout << "           Select N, D, or Q: ";
	cin >> chrAnswer;
	chrAnswer = toupper(chrAnswer);

	return chrAnswer;
}//end Menu function


void clearPlayerHands(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer) {

	//clears vector for next game
	for (int intPlayerCount = 0; 
		intPlayerCount < intpNumberOfPlayers; 
		intPlayerCount++) {

		vtrpObjPlayer.at(intPlayerCount).clearHand();
	}
}//end clearPlayerHand function


void placeYourBets(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer) { 

	int intTempBet = 0;

	//taking in player bets
	for (int intPlayerCount = 0; 
		intPlayerCount < intpNumberOfPlayers; 
		intPlayerCount++) {

		intTempBet = 
			vtrpObjPlayer.at(intPlayerCount).inputPlayerBet();
		vtrpObjPlayer.at(intPlayerCount).setBet(intTempBet);
	}
	
}//end placeYourBets


void setPlayerNames(
	int& intpNumberOfPlayers, 
	vector<Player>& vtrpObjPlayer) {
	string strPlayerName = "";

	//taking in player name with min size of 4 chars
	for (int intPlayerCnt = 0; 
		intPlayerCnt < intpNumberOfPlayers;
		intPlayerCnt++) {

		do {
			cout << "Please enter the name of Player " << 
				intPlayerCnt +1 << ": ";

			cin >> strPlayerName;

		} while (strPlayerName.size() < 4);
		
		vtrpObjPlayer.at(intPlayerCnt).setPlayerName(strPlayerName);
	}
}//end setPlayerNames


void addPlayerWinningsSubtractDealerLosses(
	int intpPosition, 
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer) {

	int intTempWinnings = 0;
	int intNewAmount = 0;
	int intDealerLosses = 0;
    
	//information and subtracting from player
	cout << endl;
	cout << vtrpObjPlayer.at(intpPosition).getPlayerName() << ",";
	cout << " you won 2 for 1!" << endl;
	cout << "Original Money Total: " << 
		vtrpObjPlayer.at(intpPosition).getMoney();
	cout << endl;
	cout << "Bet Amount: " << 
		vtrpObjPlayer.at(intpPosition).getBet();
	cout << endl;

	//bet pays 2 to 1
	intTempWinnings = vtrpObjPlayer.at(intpPosition).getBet() * 2; 
	//adding winnings to current amount
	intNewAmount = vtrpObjPlayer.at(intpPosition).getMoney() + 
		intTempWinnings;

	cout << "Winnings: " << intTempWinnings << endl;
	cout << "New Money Total: " << intNewAmount << endl;
	cout << endl;

	//setting new money amount for player
	vtrpObjPlayer.at(intpPosition).setMoney(intNewAmount);

	intDealerLosses = objpDealer.getMoney() - objpDealer.getBet();

	//subtract Player's winnings from Dealer's Money
	objpDealer.setMoney(intDealerLosses);
}//end addPlayerWinningsSubtractDealerLosses


void subtractPlayerLossesAddDealerWinnings(
	int intpPosition, 
	vector<Player>& vtrpObjPlayer, 
	Player& objpDealer) {

	int intNewAmount = 0;
	int intDealerWinnings = 0;

	//information and subtracting from player
	cout << vtrpObjPlayer.at(intpPosition).getPlayerName() << ",";
	cout << " you currently have " << 
		vtrpObjPlayer.at(intpPosition).getMoney();
	cout << endl;
	cout << "You have lost." << endl;
	cout << "Your bet was " << 
		vtrpObjPlayer.at(intpPosition).getBet();

	intNewAmount = vtrpObjPlayer.at(intpPosition).getMoney() - 
		vtrpObjPlayer.at(intpPosition).getBet();

	cout << " Your new balance is: " << intNewAmount << endl;
	cout << endl;
	
	//setting new money for player
	vtrpObjPlayer.at(intpPosition).setMoney(intNewAmount);

	intDealerWinnings = objpDealer.getMoney() + 
		(objpDealer.getBet() * 2);
	//add Player's loss to Dealer's Money
	objpDealer.setMoney(intDealerWinnings);
}//end subtractPlayerLossesAddDealerWinnings


void winnerDeterminedByMoney(
	int& intpNumberOfPlayers, 
	vector<Player> vtrpObjPlayer) {

	//make a temperary Player object
	Player gameWinner;

	cout << "GAME OVER::::::DEALER CANNOT COVER DEBTS." << endl;

	//printing off plyaer data
	for (int intPlayerCount = 0; 
		intPlayerCount < intpNumberOfPlayers; 
		intPlayerCount++) {

		cout << "Player Name:" << 
			vtrpObjPlayer.at(intPlayerCount).getPlayerName();
		cout << " Money Amount:" << 
			vtrpObjPlayer.at(intPlayerCount).getMoney();
		cout << endl;
		cout << endl;
	}

	gameWinner = vtrpObjPlayer.at(0);

	//determine winning money amount
	for (int intPlayerCount = 0; 
		intPlayerCount < intpNumberOfPlayers; 
		intPlayerCount++) {

		if (gameWinner.getMoney() < 
			vtrpObjPlayer.at(intPlayerCount).getMoney()) {
			gameWinner = vtrpObjPlayer.at(intPlayerCount);
		}
		
	}
	
	//determine winner or winners who received winning amount
	for (int intPlayerCount = 0;
		intPlayerCount < intpNumberOfPlayers;
		intPlayerCount++) {
		//looking for winner or a tie
		if (gameWinner.getMoney() ==
			vtrpObjPlayer.at(intPlayerCount).getMoney()) {
			cout << "Winner of Game:" << 
				vtrpObjPlayer.at(intPlayerCount).getPlayerName();
			cout << endl;
			cout << "Player Money Amount:" << 
				vtrpObjPlayer.at(intPlayerCount).getMoney();
			cout << endl;
		}
	}
}//end winnerDeterminedByMoney

bool playRoundAgain(
	int& intpNumberOfPlayers,
	vector<Player>& vtrpObjPlayer,
	Player& objpDealer) {

	char chrAnswer = 'Y';
	bool boolIsPlayingAgain = true;

	//if the Dealer has zero money the game is over
	//the game winner is determined by money
	if (objpDealer.getMoney() == 0) {
		winnerDeterminedByMoney(intpNumberOfPlayers, vtrpObjPlayer);
		boolIsPlayingAgain = false;
		}

	//players with no money would not be able to continue to the next round
	if (determineCombinedPlayerMoney(
		intpNumberOfPlayers,
		vtrpObjPlayer) == 0) {

		cout << "All players are out of money. ";
		cout << "Thank you for playing." << endl;
		boolIsPlayingAgain = false;
		}
	else {
		deletePlayersWithNoMoney(intpNumberOfPlayers, vtrpObjPlayer);
		cout << endl;

		//if Dealer busts, then goes to main menu
		if (boolIsPlayingAgain == true) {
			cout << "Players with money, another round?" << endl;
			cout << "Round will not continue with one player";
			cout << endl;
			cout << "(Y)es or (E)nd Round: ";
			cin >> chrAnswer;
			chrAnswer = toupper(chrAnswer);

			if (chrAnswer == 'Y' && intpNumberOfPlayers >= 2) {
				boolIsPlayingAgain = true;
			}
			else {
				boolIsPlayingAgain = false;
			}
		}
	}
	return boolIsPlayingAgain;
}//end playRoundAgain funciton

void deletePlayersWithNoMoney(
	int& intpNumberOfPlayers,
	vector<Player>& vtrpObjPlayer) {
	int intTempCounter = 0;


	//checking for players with money accouts at zero
	for (int intPlayerCount = intpNumberOfPlayers - 1 ;
		intPlayerCount >= 0;
		intPlayerCount--) {

		if (vtrpObjPlayer.at(intPlayerCount).getMoney() == 0) {

			cout << vtrpObjPlayer.at(intPlayerCount).getPlayerName();
			cout << " has no money and cannot continue.";
			cout << endl;

			//erase player from vector so the player cannot continue
			vtrpObjPlayer.erase(
				vtrpObjPlayer.begin() + intPlayerCount);
			intTempCounter += intTempCounter + 1;
		}
	}

	//updates the number of players who are left with money
	intpNumberOfPlayers = intpNumberOfPlayers - intTempCounter;
}// end deletePlayersWithNoMoney




int determineCombinedPlayerMoney(
	int& intpNumberOfPlayers,
	vector<Player>& vtrpObjPlayer) {
	int intSumOfMoney = 0;

	//find the combined amount of money of players
	//trying to see if it is zero in other function
	for (int intPlayerCount = 0;
		intPlayerCount < intpNumberOfPlayers;
		intPlayerCount++) {

		intSumOfMoney +=
			vtrpObjPlayer.at(intPlayerCount).getMoney();
	}

	return intSumOfMoney;
}//end determineCombinedPlayerMoney


