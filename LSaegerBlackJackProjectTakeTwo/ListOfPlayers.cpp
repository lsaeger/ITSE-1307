#include "stdafx.h"
#include "ListOfPlayers.h"
#include <vector>
#include <string>


ListOfPlayers::ListOfPlayers()
{
	vtrListOfPlayers.clear();
}


ListOfPlayers::~ListOfPlayers()
{
	vtrListOfPlayers.clear();
}



int ListOfPlayers::addPlayer(Player objPlayer)
{
	vtrListOfPlayers.push_back(objPlayer);
	
	return vtrListOfPlayers.size();
}


int ListOfPlayers::deleterPlayer(int intpVectorPosition)
{
	int intSizeBeforeDeleting = 0;
	int intSizeAfterDeleting = 0;

	intSizeBeforeDeleting = vtrListOfPlayers.size();
	vtrListOfPlayers.erase(vtrListOfPlayers.begin() + intpVectorPosition);
	intSizeAfterDeleting = vtrListOfPlayers.size();

	return 0;
}


Player ListOfPlayers::getPlayer(int intpVectorPosition)
{
	vtrListOfPlayers.at(intpVectorPosition);
	return Player();
}
