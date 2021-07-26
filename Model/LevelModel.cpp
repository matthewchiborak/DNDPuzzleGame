#include "LevelModel.h"

#include "../BoardObjectActions/BoardObjectActionMove.h"
#include "../BoardObjectActions/BoardObjectActionNone.h"

#include <iostream>

LevelModel::LevelModel()
	: ILevelModel()
{
	currentPlayer = nullptr;
}

bool LevelModel::playerMove(int x, int y)
{
	currentPlayer->setLastDirMoved(x, y);

	BoardObject* occupiedRef;

	if (isSpaceOccupied(currentPlayer->getPosX() + x, currentPlayer->getPosY() + y, &occupiedRef))
		return false;

	currentPlayer->setCurrentAction(new BoardObjectActionMove(
		currentPlayer,
		currentPlayer->getPosX(),
		currentPlayer->getPosY(),
		currentPlayer->getPosX() + x,
		currentPlayer->getPosY() + y
		));

	return true;
}

void LevelModel::playerStop()
{
	currentPlayer->setCurrentAction(new BoardObjectActionNone());
}

void LevelModel::playerChange(bool next)
{
	if (next)
	{
		currentPlayerIndex++;
		if (currentPlayerIndex >= players.size())
			currentPlayerIndex = 0;
	}
	else 
	{
		currentPlayerIndex--;
		if (currentPlayerIndex < 0)
			currentPlayerIndex = players.size() - 1;
	}
		
	currentPlayer = players.at(currentPlayerIndex);
}

bool LevelModel::interact()
{
	if (currentPlayer)
	{
		BoardObject* occupiedRef;

		if(isSpaceOccupied(currentPlayer->getPosX() + currentPlayer->getLastDirMovedX(), currentPlayer->getPosY() + currentPlayer->getLastDirMovedY(), &occupiedRef))
			return currentPlayer->interact(occupiedRef, this);
	}

	return false;
}

void LevelModel::addPlayer(BoardObject* player)
{
	currentPlayerIndex = 0;
	boardObjects.push_back(player);
	players.push_back(player);

	if (players.size() == 1)
		currentPlayer = player;
}

void LevelModel::addObstacle(BoardObject* obs)
{
	boardObjects.push_back(obs);
	obstacles.push_back(obs);
}

bool LevelModel::isSpaceOccupied(int x, int y, BoardObject** occupyingRef)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getPosX() == x && players.at(i)->getPosY() == y)
		{
			(*occupyingRef) = players.at(i);
			return true;
		}
	}

	for (int i = 0; i < obstacles.size(); i++)
	{
		if (obstacles.at(i)->getPosX() == x && obstacles.at(i)->getPosY() == y)
		{
			(*occupyingRef) = obstacles.at(i);
			return true;
		}
	}

	return false;
}
