#include "InteractCommandRockPush.h"

#include <iostream>

#include "../BoardObjectActions/BoardObjectActionMove.h"

InteractCommandRockPush::InteractCommandRockPush()
{
}

bool InteractCommandRockPush::execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model)
{
	//Find where the rock will stop
	int xDir = initer->getLastDirMovedX();
	int yDir = initer->getLastDirMovedY();

	std::vector<BoardObject*>::iterator it = model->getBoardObjects();
	std::vector<BoardObject*>::iterator end = model->getBoardObjectsEnd();

	int closestValue = 0;
	bool closestSet = false;
	//if(!reciever->isLevitating())
	{
		while (it != end)
		{
			if ((*it) == reciever)
			{
				it++;
				continue;
			}

			if ((*it)->isSolid() && (!isAPitOrWater(model, (*it)->getPosX(), (*it)->getPosY()) || (isAPitOrWater(model, (*it)->getPosX(), (*it)->getPosY()) && !reciever->isLevitating())))
			{
				if (xDir > 0)
				{
					if ((*it)->getPosY() == reciever->getPosY() && (*it)->getPosX() > reciever->getPosX())
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
					if ((*it)->getPosY() == reciever->getPosY() && (*it)->getPosX() < reciever->getPosX())
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
					if ((*it)->getPosX() == reciever->getPosX() && (*it)->getPosY() > reciever->getPosY())
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
					if ((*it)->getPosX() == reciever->getPosX() && (*it)->getPosY() < reciever->getPosY())
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
	}

	//Might be hitting the edge of the map. Find the next space that doesnt exist
	if (!closestSet)
	{
		if (xDir > 0)
		{
			closestValue = reciever->getPosX() + 1;
			if (!(model->doesSpaceExist(closestValue, reciever->getPosY())))
				return false;
			do
			{
				closestValue++;
			} while (model->doesSpaceExist(closestValue, reciever->getPosY()) || isAPitOrWater(model, closestValue, reciever->getPosY()));
			closestValue--;
		}
		else if (xDir < 0)
		{
			closestValue = reciever->getPosX() - 1;
			if (!(model->doesSpaceExist(closestValue, reciever->getPosY())))
				return false;
			do
			{
				closestValue--;
			} while (model->doesSpaceExist(closestValue, reciever->getPosY()) || isAPitOrWater(model, closestValue, reciever->getPosY()));
			closestValue++;
		}
		else if (yDir > 0)
		{
			closestValue = reciever->getPosY() + 1;
			if (!(model->doesSpaceExist(reciever->getPosX(), closestValue)))
				return false;
			do
			{
				closestValue++;
			} while (model->doesSpaceExist(reciever->getPosX(), closestValue) || isAPitOrWater(model, reciever->getPosX(), closestValue));
			closestValue--;
		}
		else if (yDir < 0)
		{
			closestValue = reciever->getPosY() - 1;
			if (!(model->doesSpaceExist(reciever->getPosX(), closestValue)))
				return false;
			do
			{
				closestValue--;
			} while (model->doesSpaceExist(reciever->getPosX(), closestValue) || isAPitOrWater(model, reciever->getPosY(), closestValue));
			closestValue++;
		}
	}

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
		return reciever->push(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), closestValue, reciever->getPosY()));
	else
		return reciever->push(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), reciever->getPosX(), closestValue));

}

bool InteractCommandRockPush::isAPitOrWater(ILevelModel* model, int x, int y)
{
	return (model->isAPit(x, y) || model->isAWater(x, y));
}
