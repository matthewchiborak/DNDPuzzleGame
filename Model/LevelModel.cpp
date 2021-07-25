#include "LevelModel.h"

#include <iostream>

LevelModel::LevelModel()
	: ILevelModel()
{
	currentPlayer = nullptr;
}

void LevelModel::interact()
{
	if(currentPlayer)
		currentPlayer->interact(boardObjects.at(0));
}

void LevelModel::addPlayer(BoardObject* player)
{
	boardObjects.push_back(player);
	players.push_back(player);

	if (players.size() == 1)
		currentPlayer = player;
}
