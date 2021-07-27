#include "InteractCommandShoot.h"

#include "../BoardObjectActions/BoardObjectActionMove.h"
#include "../Model/ArrowBoardObject.h"
#include "../BoardObjectActions/BoardObjectActionNone.h"
#include "../Model/LevelModel.h"

#include <iostream>

InteractCommandShoot::InteractCommandShoot(std::string arrowModelKey, LevelModel* model)
	: InteractCommand(model)
{
	this->arrowModelKey = arrowModelKey;
}

bool InteractCommandShoot::execute(BoardObject* initer, BoardObject* otherObj)
{
	this->initer = initer;

	//Find where arrow will stop
	int xDir = initer->getLastDirMovedX();
	int yDir = initer->getLastDirMovedY();

	int closestValue = 0;
	bool closestSet = false;

	for (int i = 0; i < this->model->getObstacles()->size(); i++)
	{
		findClosestValue(xDir, yDir, (*model->getObstacles())[i]->getPosX(), (*model->getObstacles())[i]->getPosY(), 1, &closestSet, &closestValue);
	}

	for (int i = 0; i < this->model->getArrows()->size(); i++)
	{
		findClosestValue(xDir, yDir, (*model->getArrows())[i]->getPosX(), (*model->getArrows())[i]->getPosY(), 1, &closestSet, &closestValue);
	}

	for (int i = 0; i < this->model->getPlayers()->size(); i++)
	{
		findClosestValue(xDir, yDir, (*model->getPlayers())[i]->getPosX(), (*model->getPlayers())[i]->getPosY(), 0, &closestSet, &closestValue);
	}

	for (int i = 0; i < this->model->getWalls()->size(); i++)
	{
		findClosestValue(xDir, yDir, (*model->getWalls())[i]->getPosX(), (*model->getWalls())[i]->getPosY(), 1, &closestSet, &closestValue);
	}

	//Check if space doesnt exist
	if (!findClosestValueNotExist(xDir, yDir, &closestSet, &closestValue))
		return false;

	//If Not moving, shoudl return false so a turn isn't used up
	if (xDir > 0 || xDir < 0)
	{
		if (initer->getPosX() == closestValue)
			return false;
	}
	else if (yDir > 0 || yDir < 0)
	{
		if (initer->getPosY() == closestValue)
			return false;
	}

	if (xDir > 0 || xDir < 0)
	{
		ArrowBoardObject* newArrow = new ArrowBoardObject(initer->getPosX(), initer->getPosY(), initer->getHeight(),
			new BoardObjectActionNone(),
			this->arrowModelKey
		);
		newArrow->setCurrentAction(new BoardObjectActionMove(newArrow, initer->getPosX(), initer->getPosY(), closestValue, initer->getPosY()));
		model->addArrow(newArrow);
		return true;
	}
	else
	{
		ArrowBoardObject* newArrow = new ArrowBoardObject(initer->getPosX(), initer->getPosY(), initer->getHeight(),
			new BoardObjectActionNone(),
			this->arrowModelKey
		);
		newArrow->setCurrentAction(new BoardObjectActionMove(newArrow, initer->getPosX(), initer->getPosY(), initer->getPosX(), closestValue));
		model->addArrow(newArrow);
		return true;
	}
}

bool InteractCommandShoot::needsReciever()
{
	return false;
}

bool InteractCommandShoot::isAPitOrWater(ILevelModel* model, int x, int y)
{
	return (model->isAPit(x, y) || model->isAWater(x, y));
}

void InteractCommandShoot::findClosestValue(int xDir, int yDir, int objectX, int objectY, int distanceOffset, bool* closestSet, int* closestValue)
{
	if (xDir > 0)
	{
		if (objectY == initer->getPosY() && objectX > initer->getPosX())
		{
			if (!(*closestSet))
			{
				(*closestValue) = objectX - distanceOffset;
				(*closestSet) = true;
			}
			else
			{
				if ((objectX - 1) < (*closestValue))
					(*closestValue) = objectX - distanceOffset;
			}
		}
	}
	else if (xDir < 0)
	{
		if (objectY == initer->getPosY() && objectX < initer->getPosX())
		{
			if (!closestSet)
			{
				(*closestValue) = objectX + distanceOffset;
				(*closestSet) = true;
			}
			else
			{
				if ((objectX + 1) > (*closestValue))
					(*closestValue) = objectX + distanceOffset;
			}
		}
	}
	else if (yDir > 0)
	{
		if (objectX == initer->getPosX() && objectY > initer->getPosY())
		{
			if (!closestSet)
			{
				(*closestValue) = objectY - distanceOffset;
				(*closestSet) = true;
			}
			else
			{
				if ((objectY - 1) < (*closestValue))
					(*closestValue) = objectY - distanceOffset;
			}
		}
	}
	else if (yDir < 0)
	{
		if (objectX == initer->getPosX() && objectY < initer->getPosY())
		{
			if (!closestSet)
			{
				(*closestValue) = objectY + distanceOffset;
				(*closestSet) = true;
			}
			else
			{
				if ((objectY + 1) > (*closestValue))
					(*closestValue) = objectY + distanceOffset;
			}
		}
	}
}

bool InteractCommandShoot::findClosestValueNotExist(int xDir, int yDir, bool* closestSet, int* closestValue)
{
	//Might be hitting the edge of the map. Find the next space that doesnt exist
	if (!(*closestSet))
	{
		if (xDir > 0)
		{
			(*closestValue) = initer->getPosX() + 1;
			if (!(model->doesSpaceExist((*closestValue), initer->getPosY())))
				return false;
			do
			{
				(*closestValue)++;
			} while (model->doesSpaceExist((*closestValue), initer->getPosY()) || isAPitOrWater(model, (*closestValue), initer->getPosY()));
			(*closestValue)--;
		}
		else if (xDir < 0)
		{
			(*closestValue) = initer->getPosX() - 1;
			if (!(model->doesSpaceExist((*closestValue), initer->getPosY())))
				return false;
			do
			{
				(*closestValue)--;
			} while (model->doesSpaceExist((*closestValue), initer->getPosY()) || isAPitOrWater(model, (*closestValue), initer->getPosY()));
			(*closestValue)++;
		}
		else if (yDir > 0)
		{
			(*closestValue) = initer->getPosY() + 1;
			if (!(model->doesSpaceExist(initer->getPosX(), (*closestValue))))
				return false;
			do
			{
				(*closestValue)++;
			} while (model->doesSpaceExist(initer->getPosX(), (*closestValue)) || isAPitOrWater(model, initer->getPosX(), (*closestValue)));
			(*closestValue)--;
		}
		else if (yDir < 0)
		{
			(*closestValue) = initer->getPosY() - 1;
			if (!(model->doesSpaceExist(initer->getPosX(), (*closestValue))))
				return false;
			do
			{
				(*closestValue)--;
			} while (model->doesSpaceExist(initer->getPosX(), (*closestValue)) || isAPitOrWater(model, initer->getPosY(), (*closestValue)));
			(*closestValue)++;
		}
	}

	return true;
}
