#include "LevelModel.h"

#include "../BoardObjectActions/BoardObjectActionMove.h"
#include "../BoardObjectActions/BoardObjectActionNone.h"
#include "../Controller/IModelModifier.h"

#include <iostream>

LevelModel::LevelModel(IModelModifier* modifier)
	: ILevelModel()
{
	currentPlayer = nullptr;
	this->modelModifier = modifier;
}

LevelModel::~LevelModel()
{
	delete modelModifier;
}

bool LevelModel::modifyModel(std::string message)
{
	return modelModifier->modify(message);
}

bool LevelModel::playerMove(int x, int y)
{
	currentPlayer->setLastDirMoved(x, y);

	BoardObject* occupiedRef;

	bool itIsAWater = false;

	std::string existText = "{\"Key\": \"SpaceExist\", \"X\": " 
		+ std::to_string(currentPlayer->getPosX() + x) 
		+ ", \"Y\": " + std::to_string(currentPlayer->getPosY() + y) + "}";

	if(!modelModifier->modify(existText))
	{
		std::string waterText = "{\"Key\": \"IsWater\", \"X\": "
			+ std::to_string(currentPlayer->getPosX() + x)
			+ ", \"Y\": " + std::to_string(currentPlayer->getPosY() + y) + "}";
		if(!modelModifier->modify(waterText))
			return false;
	}
	
	if (isSpaceOccupied(currentPlayer->getPosX() + x, currentPlayer->getPosY() + y, &occupiedRef))
		return false;

	currentPlayer->setCurrentAction(new BoardObjectActionMove(
		currentPlayer,
		currentPlayer->getPosX(),
		currentPlayer->getPosY(),
		currentPlayer->getPosX() + x,
		currentPlayer->getPosY() + y
		));

	std::string meltText = "{\"Key\": \"CheckMelt\", \"sx\": "
		+ std::to_string(currentPlayer->getPosX())
		+ ", \"sy\": " + std::to_string(currentPlayer->getPosY())
		+ ", \"ex\": " + std::to_string(currentPlayer->getPosX() + x)
		+ ", \"ey\": " + std::to_string(currentPlayer->getPosY() + y)
		+ "}";
	this->modelModifier->modify(meltText);

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

		if(!currentPlayer->needsInteractReciever())
			return currentPlayer->interact(nullptr);

		if (isSpaceOccupied(currentPlayer->getPosX() + currentPlayer->getLastDirMovedX(), currentPlayer->getPosY() + currentPlayer->getLastDirMovedY(), &occupiedRef))
		{
			return currentPlayer->interact(occupiedRef);
		}
	}

	return false;
}

void LevelModel::addArrow(ArrowBoardObject* obj)
{
	boardObjects.push_back(obj);
	arrows.push_back(obj);
}

void LevelModel::addTile(TileBoardObject* tile)
{
	boardObjects.push_back(tile);
	tiles.push_back(tile);
}

void LevelModel::addPlayer(PlayerBoardObject* player)
{
	currentPlayerIndex = 0;
	boardObjects.push_back(player);
	players.push_back(player);

	if (players.size() == 1)
		currentPlayer = player;
}

void LevelModel::addObstacle(ObstacleBoardObject* obs)
{
	boardObjects.push_back(obs);
	obstacles.push_back(obs);
}

void LevelModel::addWall(WallBoardObject* wall)
{
	boardObjects.push_back(wall);
	walls.push_back(wall);
}

void LevelModel::addPit(PitBoardObject* pit)
{
	boardObjects.push_back(pit);
	pits.push_back(pit);
}

void LevelModel::addWater(WaterBoardObject* water)
{
	boardObjects.push_back(water);
	this->water.push_back(water);
}

std::vector<TileBoardObject*>* LevelModel::getTiles()
{
	return &tiles;
}

std::vector<PlayerBoardObject*>* LevelModel::getPlayers()
{
	return &players;
}

std::vector<ObstacleBoardObject*>* LevelModel::getObstacles()
{
	return &obstacles;
}

std::vector<WallBoardObject*>* LevelModel::getWalls()
{
	return &walls;
}

std::vector<PitBoardObject*>* LevelModel::getPits()
{
	return &pits;
}

std::vector<WaterBoardObject*>* LevelModel::getWater()
{
	return &water;
}

std::vector<ArrowBoardObject*>* LevelModel::getArrows()
{
	return &arrows;
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

	for (int i = 0; i < arrows.size(); i++)
	{
		if (arrows.at(i)->getPosX() == x && arrows.at(i)->getPosY() == y)
		{
			(*occupyingRef) = arrows.at(i);
			return true;
		}
	}

	for (int i = 0; i < water.size(); i++)
	{
		if (water.at(i)->getPosX() == x && water.at(i)->getPosY() == y)
		{
			(*occupyingRef) = water.at(i);
			return water.at(i)->isSolid();
		}
	}

	return false;
}

