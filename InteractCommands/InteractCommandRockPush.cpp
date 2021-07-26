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

	int closestValue;
	bool closestSet = false;

	while (it != end)
	{
		if ((*it) == reciever)
		{
			it++;
			continue;
		}

		if ((*it)->isSolid())
		{
			if (xDir > 0)
			{
				if ((*it)->getPosY() == reciever->getPosY() && (*it)->getPosX() < reciever->getPosX())
				{
					if (!closestSet)
					{
						closestValue = reciever->getPosX() - 1;
						closestSet = true;
					}
					else
					{
						if((reciever->getPosX() - 1) < closestValue)
							closestValue = reciever->getPosX() - 1;
					}
				}
			}
			else if (xDir < 0)
			{
				if ((*it)->getPosY() == reciever->getPosY() && (*it)->getPosX() > reciever->getPosX())
				{
					if (!closestSet)
					{
						closestValue = reciever->getPosX() + 1;
						closestSet = true;
					}
					else
					{
						if ((reciever->getPosX() + 1) < closestValue)
							closestValue = reciever->getPosX() + 1;
					}
				}
			}
			else if (yDir > 0)
			{
				if ((*it)->getPosX() == reciever->getPosX() && (*it)->getPosY() < reciever->getPosY())
				{
					if (!closestSet)
					{
						closestValue = reciever->getPosY() - 1;
						closestSet = true;
					}
					else
					{
						if ((reciever->getPosY() - 1) < closestValue)
							closestValue = reciever->getPosY() - 1;
					}
				}
			}
			else if (yDir < 0)
			{
				if ((*it)->getPosX() == reciever->getPosX() && (*it)->getPosY() > reciever->getPosY())
				{
					if (!closestSet)
					{
						closestValue = reciever->getPosY() + 1;
						closestSet = true;
					}
					else
					{
						if ((reciever->getPosY() + 1) < closestValue)
							closestValue = reciever->getPosY() + 1;
					}
				}
			}
		}
		it++;
	}

	if (xDir > 0 || xDir < 0)
		reciever->setCurrentAction(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), closestValue, reciever->getPosY()));
	else
		reciever->setCurrentAction(new BoardObjectActionMove(reciever, reciever->getPosX(), reciever->getPosY(), reciever->getPosX(), closestValue));

	return true;
}
