#include "InteractCommandShoot.h"

#include "../BoardObjectActions/BoardObjectActionMove.h"
#include "../Model/ArrowBoardObject.h"
#include "../BoardObjectActions/BoardObjectActionNone.h"

#include <iostream>

InteractCommandShoot::InteractCommandShoot(std::string arrowModelKey)
{
	this->arrowModelKey = arrowModelKey;
}

bool InteractCommandShoot::execute(BoardObject* initer, BoardObject* reciver, ILevelModel* model)
{
	//Find where arrow will stop
	int xDir = initer->getLastDirMovedX();
	int yDir = initer->getLastDirMovedY();

	std::vector<BoardObject*>::iterator it = model->getBoardObjects();
	std::vector<BoardObject*>::iterator end = model->getBoardObjectsEnd();

	int closestValue = 0;
	bool closestSet = false;

	while (it != end)
	{

		if ((*it)->isSolid() && (!isAPitOrWater(model, (*it)->getPosX(), (*it)->getPosY())))
		{
			if (xDir > 0)
			{
				if ((*it)->getPosY() == initer->getPosY() && (*it)->getPosX() > initer->getPosX())
				{
					if (!closestSet)
					{
						closestValue = (*it)->getPosX() - (((*it)->isSquishy()) ? 0 : 1);
						closestSet = true;
					}
					else
					{
						if (((*it)->getPosX() - 1) < closestValue)
							closestValue = (*it)->getPosX() - (((*it)->isSquishy()) ? 0 : 1);;
					}
				}
			}
			else if (xDir < 0)
			{
				if ((*it)->getPosY() == initer->getPosY() && (*it)->getPosX() < initer->getPosX())
				{
					if (!closestSet)
					{
						closestValue = (*it)->getPosX() + (((*it)->isSquishy()) ? 0 : 1);;
						closestSet = true;
					}
					else
					{
						if (((*it)->getPosX() + 1) > closestValue)
							closestValue = (*it)->getPosX() + (((*it)->isSquishy()) ? 0 : 1);;
					}
				}
			}
			else if (yDir > 0)
			{
				if ((*it)->getPosX() == initer->getPosX() && (*it)->getPosY() > initer->getPosY())
				{
					if (!closestSet)
					{
						closestValue = (*it)->getPosY() - (((*it)->isSquishy()) ? 0 : 1);;
						closestSet = true;
					}
					else
					{
						if (((*it)->getPosY() - 1) < closestValue)
							closestValue = (*it)->getPosY() - (((*it)->isSquishy()) ? 0 : 1);;
					}
				}
			}
			else if (yDir < 0)
			{
				if ((*it)->getPosX() == initer->getPosX() && (*it)->getPosY() < initer->getPosY())
				{
					if (!closestSet)
					{
						closestValue = (*it)->getPosY() + (((*it)->isSquishy()) ? 0 : 1);;
						closestSet = true;
					}
					else
					{
						if (((*it)->getPosY() + 1) > closestValue)
							closestValue = (*it)->getPosY() + (((*it)->isSquishy()) ? 0 : 1);;
					}
				}
			}
		}
		it++;
	}

	//Might be hitting the edge of the map. Find the next space that doesnt exist
	if (!closestSet)
	{
		if (xDir > 0)
		{
			closestValue = initer->getPosX() + 1;
			if (!(model->doesSpaceExist(closestValue, initer->getPosY())))
				return false;
			do
			{
				closestValue++;
			} while (model->doesSpaceExist(closestValue, initer->getPosY()) || isAPitOrWater(model, closestValue, initer->getPosY()));
			closestValue--;
		}
		else if (xDir < 0)
		{
			closestValue = initer->getPosX() - 1;
			if (!(model->doesSpaceExist(closestValue, initer->getPosY())))
				return false;
			do
			{
				closestValue--;
			} while (model->doesSpaceExist(closestValue, initer->getPosY()) || isAPitOrWater(model, closestValue, initer->getPosY()));
			closestValue++;
		}
		else if (yDir > 0)
		{
			closestValue = initer->getPosY() + 1;
			if (!(model->doesSpaceExist(initer->getPosX(), closestValue)))
				return false;
			do
			{
				closestValue++;
			} while (model->doesSpaceExist(initer->getPosX(), closestValue) || isAPitOrWater(model, initer->getPosX(), closestValue));
			closestValue--;
		}
		else if (yDir < 0)
		{
			closestValue = initer->getPosY() - 1;
			if (!(model->doesSpaceExist(initer->getPosX(), closestValue)))
				return false;
			do
			{
				closestValue--;
			} while (model->doesSpaceExist(initer->getPosX(), closestValue) || isAPitOrWater(model, initer->getPosY(), closestValue));
			closestValue++;
		}
	}

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

	return true;
}

bool InteractCommandShoot::needsReciever()
{
	return false;
}

bool InteractCommandShoot::isAPitOrWater(ILevelModel* model, int x, int y)
{
	return (model->isAPit(x, y) || model->isAWater(x, y));
}
