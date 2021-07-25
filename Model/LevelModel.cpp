#include "LevelModel.h"

#include "../BoardObjectActions/BoardObjectActionMove.h"
#include "../BoardObjectActions/BoardObjectActionNone.h"

#include <iostream>

LevelModel::LevelModel()
	: ILevelModel()
{
	currentPlayer = nullptr;
}

void LevelModel::playerMove(int x, int y)
{
	currentPlayer->setCurrentAction(new BoardObjectActionMove(
		currentPlayer,
		currentPlayer->getPosX(),
		currentPlayer->getPosY(),
		currentPlayer->getPosX() + x,
		currentPlayer->getPosY() + y
		));
}

void LevelModel::playerStop()
{
	currentPlayer->setCurrentAction(new BoardObjectActionNone());
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
