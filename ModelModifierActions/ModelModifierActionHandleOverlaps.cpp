#include "ModelModifierActionHandleOverlaps.h"

ModelModifierActionHandleOverlaps::ModelModifierActionHandleOverlaps(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionHandleOverlaps::execute(nlohmann::json* message)
{
	handleOverlapsRocks();
	handleOverlapsArrows();
	return true;
}

void ModelModifierActionHandleOverlaps::handleOverlapsArrows()
{
	//Arrows
	std::vector<ArrowBoardObject*>::iterator iterArrow = this->level->getArrows()->begin();
	std::vector<ArrowBoardObject*>::iterator endArrow = this->level->getArrows()->end();
	while (iterArrow != endArrow)
	{
		//Players
		std::vector<PlayerBoardObject*>::iterator iter = this->level->getPlayers()->begin();
		std::vector<PlayerBoardObject*>::iterator end = this->level->getPlayers()->end();
		while (iter != end)
		{
			if ((*iterArrow)->getPosX() == (*iter)->getPosX() && (*iterArrow)->getPosY() == (*iter)->getPosY())
			{
				std::vector<BoardObject*>::iterator iterO = this->level->getBoardObjects();
				std::vector<BoardObject*>::iterator endO = this->level->getBoardObjectsEnd();
				while (iterO != endO)
				{
					if ((*iterO) == (*iter))
					{
						this->level->getBoardObjectsVector()->erase(iterO);
						break;
					}
					iterO++;
				}

				delete (*iter);
				this->level->getPlayers()->erase(iter);
				return;
			}

			iter++;
		}

		iterArrow++;
	}
}

void ModelModifierActionHandleOverlaps::handleOverlapsRocks()
{
	//Rocks
	//If rock and hole, create a new tile
	std::vector<ObstacleBoardObject*>::iterator iterRock = this->level->getObstacles()->begin();
	std::vector<ObstacleBoardObject*>::iterator endRock = this->level->getObstacles()->end();
	while (iterRock != endRock)
	{
		//Players
		std::vector<PlayerBoardObject*>::iterator iter = this->level->getPlayers()->begin();
		std::vector<PlayerBoardObject*>::iterator end = this->level->getPlayers()->end();
		while (iter != end)
		{
			if ((*iterRock)->getPosX() == (*iter)->getPosX() && (*iterRock)->getPosY() == (*iter)->getPosY())
			{
				std::vector<BoardObject*>::iterator iterO = this->level->getBoardObjects();
				std::vector<BoardObject*>::iterator endO = this->level->getBoardObjectsEnd();
				while (iterO != endO)
				{
					if ((*iterO) == (*iter))
					{
						this->level->getBoardObjectsVector()->erase(iterO);
						break;
					}
					iterO++;
				}

				delete (*iter);
				this->level->getPlayers()->erase(iter);
				return;
			}

			iter++;
		}

		//Water
		std::vector<WaterBoardObject*>::iterator iterWater = this->level->getWater()->begin();
		std::vector<WaterBoardObject*>::iterator endWater = this->level->getWater()->end();
		while (iterWater != endWater)
		{
			if ((*iterRock)->getPosX() == (*iterWater)->getPosX() && (*iterRock)->getPosY() == (*iterWater)->getPosY())
			{
				std::vector<BoardObject*>::iterator iterO = this->level->getBoardObjects();
				std::vector<BoardObject*>::iterator endO = this->level->getBoardObjectsEnd();
				while (iterO != endO)
				{
					if ((*iterO) == (*iterRock))
					{
						this->level->getBoardObjectsVector()->erase(iterO);
						break;
					}
					iterO++;
				}

				delete (*iterRock);
				this->level->getObstacles()->erase(iterRock);
				return;
			}

			iterWater++;
		}

		//Pits
		std::vector<PitBoardObject*>::iterator iterPit = this->level->getPits()->begin();
		std::vector<PitBoardObject*>::iterator endPit = this->level->getPits()->end();
		while (iterPit != endPit)
		{
			if ((*iterRock)->getPosX() == (*iterPit)->getPosX() && (*iterRock)->getPosY() == (*iterPit)->getPosY())
			{
				std::vector<BoardObject*>::iterator iterO = this->level->getBoardObjects();
				std::vector<BoardObject*>::iterator endO = this->level->getBoardObjectsEnd();
				while (iterO != endO)
				{
					if ((*iterO) == (*iterPit))
					{
						this->level->getBoardObjectsVector()->erase(iterO);
						break;
					}
					iterO++;
				}
				iterO = this->level->getBoardObjects();
				endO = this->level->getBoardObjectsEnd();
				while (iterO != endO)
				{
					if ((*iterO) == (*iterRock))
					{
						this->level->getBoardObjectsVector()->erase(iterO);
						break;
					}
					iterO++;
				}

				int rockPosX = (*iterRock)->getPosX();
				int rockPosY = (*iterRock)->getPosY();

				delete (*iterPit);
				this->level->getPits()->erase(iterPit);
				delete (*iterRock);
				this->level->getObstacles()->erase(iterRock);

				TileBoardObject* newTile = this->level->getTiles()->at(0)->copy();
				newTile->setPos(rockPosX, rockPosY);
				newTile->setVis(rockPosX / 10.0f, rockPosY / 10.0f);
				this->level->addTile(newTile);

				return;
			}

			iterPit++;
		}

		iterRock++;
	}
}
