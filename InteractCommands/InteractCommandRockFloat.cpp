#include "InteractCommandRockFloat.h"

InteractCommandRockFloat::InteractCommandRockFloat()
{
}

bool InteractCommandRockFloat::execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model)
{
	//Float the reciever if not floating already
	if (reciever->isLevitating())
		return false;

	//If success float a rock, put any others that are floating down
	if (!reciever->levitateMe())
	{
		return false;
	}

	//Is leviating. Make all other object touch the ground
	std::vector<BoardObject*>::iterator it = model->getBoardObjects();
	std::vector<BoardObject*>::iterator end = model->getBoardObjectsEnd();

	while (it != end)
	{
		if ((*it) == reciever)
		{
			it++;
			continue;
		}

		(*it)->stopLevitate();
		it++;
	}

	return true;
}
