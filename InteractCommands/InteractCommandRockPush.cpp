#include "InteractCommandRockPush.h"

#include <iostream>

#include "../BoardObjectActions/BoardObjectActionMove.h"
#include "../Model/LevelModel.h"

InteractCommandRockPush::InteractCommandRockPush(LevelModel* model)
	: InteractCommand(model)
{
}

void InteractCommandRockPush::setReciever(ObstacleBoardObject* reciever)
{
	this->reciever = reciever;
}

bool InteractCommandRockPush::execute(BoardObject* initer, BoardObject* otherObj)
{
	for (int i = 0; i < this->model->getObstacles()->size(); i++)
	{
		if ((*this->model->getObstacles())[i] == otherObj)
			setReciever((*this->model->getObstacles())[i]);
	}

	return (reciever->isLevitating()) ? executeForReceiverIsFloating(initer) : executeForReceiverIsOnTheGround(initer);
}

bool InteractCommandRockPush::needsReciever()
{
	return true;
}

bool InteractCommandRockPush::isAPitOrWater(ILevelModel* model, int x, int y)
{
	return (model->isAPit(x, y) || model->isAWater(x, y));
}

bool InteractCommandRockPush::executeForReceiverIsFloating(BoardObject* initer)
{
	int xDir = initer->getLastDirMovedX();
	int yDir = initer->getLastDirMovedY();

	int closestValue = 0;
	bool closestSet = false;

	for (int i = 0; i < this->model->getObstacles()->size(); i++)
	{
		//Don't compare to itself
		if (this->reciever == (*model->getObstacles())[i])
			continue;
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
		if (reciever->getPosX() == closestValue)
			return false;
	}
	else if (yDir > 0 || yDir < 0)
	{
		if (reciever->getPosY() == closestValue)
			return false;
	}

	if (xDir > 0 || xDir < 0)
	{
		return reciever->push(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), closestValue, reciever->getPosY()));
	}
	else
	{
		return reciever->push(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), reciever->getPosX(), closestValue));
	}
}

bool InteractCommandRockPush::executeForReceiverIsOnTheGround(BoardObject* initer)
{
	int xDir = initer->getLastDirMovedX();
	int yDir = initer->getLastDirMovedY();

	int closestValue = 0;
	bool closestSet = false;

	for (int i = 0; i < this->model->getObstacles()->size(); i++)
	{
		//Don't compare to itself
		if (this->reciever == (*model->getObstacles())[i])
			continue;
		findClosestValue(xDir, yDir, (*model->getObstacles())[i]->getPosX(), (*model->getObstacles())[i]->getPosY(), 1, &closestSet, &closestValue);
	}

	for (int i = 0; i < this->model->getPits()->size(); i++)
	{
		findClosestValue(xDir, yDir, (*model->getPits())[i]->getPosX(), (*model->getPits())[i]->getPosY(), 0, &closestSet, &closestValue);
	}

	for (int i = 0; i < this->model->getWater()->size(); i++)
	{
		if((*model->getWater())[i]->isSolid())
			findClosestValue(xDir, yDir, (*model->getWater())[i]->getPosX(), (*model->getWater())[i]->getPosY(), 0, &closestSet, &closestValue);
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
		if (reciever->getPosX() == closestValue)
			return false;
	}
	else if (yDir > 0 || yDir < 0)
	{
		if (reciever->getPosY() == closestValue)
			return false;
	}

	if (xDir > 0 || xDir < 0)
	{
		model->checkForMelt(reciever->getPosX(), reciever->getPosY(), closestValue, reciever->getPosY());
		return reciever->push(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), closestValue, reciever->getPosY()));
	}
	else
	{
		model->checkForMelt(reciever->getPosX(), reciever->getPosY(), reciever->getPosX(), closestValue);
		return reciever->push(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), reciever->getPosX(), closestValue));
	}
}

void InteractCommandRockPush::findClosestValue(int xDir, int yDir, int objectX, int objectY, int distanceOffset, bool* closestSet, int* closestValue)
{
	if (xDir > 0)
	{
		if (objectY == reciever->getPosY() && objectX > reciever->getPosX())
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
		if (objectY == reciever->getPosY() && objectX < reciever->getPosX())
		{
			if (!(*closestSet))
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
		if (objectX == reciever->getPosX() && objectY > reciever->getPosY())
		{
			if (!(*closestSet))
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
		if (objectX == reciever->getPosX() && objectY < reciever->getPosY())
		{
			if (!(*closestSet))
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

bool InteractCommandRockPush::findClosestValueNotExist(int xDir, int yDir, bool* closestSet, int* closestValue)
{
	//Might be hitting the edge of the map. Find the next space that doesnt exist
	if (!(*closestSet))
	{
		if (xDir > 0)
		{
			(*closestValue) = reciever->getPosX() + 1;
			if (!(model->doesSpaceExist((*closestValue), reciever->getPosY())))
				return false;
			do
			{
				(*closestValue)++;
			} while (model->doesSpaceExist((*closestValue), reciever->getPosY()) || isAPitOrWater(model, (*closestValue), reciever->getPosY()));
			(*closestValue)--;
		}
		else if (xDir < 0)
		{
			(*closestValue) = reciever->getPosX() - 1;
			if (!(model->doesSpaceExist((*closestValue), reciever->getPosY())))
				return false;
			do
			{
				(*closestValue)--;
			} while (model->doesSpaceExist((*closestValue), reciever->getPosY()) || isAPitOrWater(model, (*closestValue), reciever->getPosY()));
			(*closestValue)++;
		}
		else if (yDir > 0)
		{
			(*closestValue) = reciever->getPosY() + 1;
			if (!(model->doesSpaceExist(reciever->getPosX(), (*closestValue))))
				return false;
			do
			{
				(*closestValue)++;
			} while (model->doesSpaceExist(reciever->getPosX(), (*closestValue)) || isAPitOrWater(model, reciever->getPosX(), (*closestValue)));
			(*closestValue)--;
		}
		else if (yDir < 0)
		{
			(*closestValue) = reciever->getPosY() - 1;
			if (!(model->doesSpaceExist(reciever->getPosX(), (*closestValue))))
				return false;
			do
			{
				(*closestValue)--;
			} while (model->doesSpaceExist(reciever->getPosX(), (*closestValue)) || isAPitOrWater(model, reciever->getPosY(), (*closestValue)));
			(*closestValue)++;
		}
	}

	return true;
}

