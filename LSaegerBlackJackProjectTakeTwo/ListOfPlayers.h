#pragma once
#include <vector>
#include <string>
#include "Player.h"

class ListOfPlayers
{
private: 
	std::vector<Player> vtrListOfPlayers;

public:
	ListOfPlayers();
	~ListOfPlayers();
	int addPlayer(Player objPlayer);
	int deleterPlayer(int intVectorpPosition);
	Player getPlayer(int intVectorpPosition);
};

