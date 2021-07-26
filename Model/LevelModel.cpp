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

	if (!doesSpaceExist(currentPlayer->getPosX() + x, currentPlayer->getPosY() + y))
		return false;

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

void LevelModel::rockStop()
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles.at(i)->setCurrentAction(new BoardObjectActionNone());
	}
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

void LevelModel::handleOverlaps()
{
	//Rocks
	//If rock and hole, create a new tile
	std::vector<BoardObject*>::iterator iterRock = obstacles.begin();
	std::vector<BoardObject*>::iterator endRock = obstacles.end();
	while(iterRock != endRock)
	{
		std::vector<BoardObject*>::iterator iter = players.begin();
		std::vector<BoardObject*>::iterator end = players.end();
		while(iter != end)
		{
			if ((*iterRock)->getPosX() == (*iter)->getPosX() && (*iterRock)->getPosY() == (*iter)->getPosY())
			{
				std::vector<BoardObject*>::iterator iterO = boardObjects.begin();
				std::vector<BoardObject*>::iterator endO = boardObjects.end();
				while (iterO != endO)
				{
					if ((*iterO) == (*iter))
					{
						boardObjects.erase(iterO);
						break;
					}
					iterO++;
				}

				delete (*iter);
				players.erase(iter);
				return;
			}

			iter++;
		}


		std::vector<BoardObject*>::iterator iterPit = pits.begin();
		std::vector<BoardObject*>::iterator endPit = pits.end();
		while (iterPit != endPit)
		{
			if ((*iterRock)->getPosX() == (*iterPit)->getPosX() && (*iterRock)->getPosY() == (*iterPit)->getPosY())
			{
				std::vector<BoardObject*>::iterator iterO = boardObjects.begin();
				std::vector<BoardObject*>::iterator endO = boardObjects.end();
				while (iterO != endO)
				{
					if ((*iterO) == (*iterPit))
					{
						boardObjects.erase(iterO);
						break;
					}
					iterO++;
				}
				iterO = boardObjects.begin();
				endO = boardObjects.end();
				while (iterO != endO)
				{
					if ((*iterO) == (*iterRock))
					{
						boardObjects.erase(iterO);
						break;
					}
					iterO++;
				}

				int rockPosX = (*iterRock)->getPosX();
				int rockPosY = (*iterRock)->getPosY();

				delete (*iterPit);
				pits.erase(iterPit);
				delete (*iterRock);
				obstacles.erase(iterRock);

				BoardObject* newTile = tiles.at(0)->copy();
				newTile->setPos(rockPosX, rockPosY);
				newTile->setVis(rockPosX / 10.0f, rockPosY / 10.0f);
				this->addTile(newTile);

				return;
			}

			iterPit++;
		}

		iterRock++;
	}
}

void LevelModel::addTile(BoardObject* tile)
{
	boardObjects.push_back(tile);
	tiles.push_back(tile);
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

void LevelModel::addWall(BoardObject* wall)
{
	boardObjects.push_back(wall);
	walls.push_back(wall);
}

void LevelModel::addPit(BoardObject* pit)
{
	boardObjects.push_back(pit);
	pits.push_back(pit);
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

	for (int i = 0; i < walls.size(); i++)
	{
		if (walls.at(i)->getPosX() == x && walls.at(i)->getPosY() == y)
		{
			(*occupyingRef) = walls.at(i);
			return true;
		}
	}

	return false;
}

bool LevelModel::doesSpaceExist(int x, int y)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		if (tiles.at(i)->getPosX() == x && tiles.at(i)->getPosY() == y)
		{
			return true;
		}
	}

	return false;
}
