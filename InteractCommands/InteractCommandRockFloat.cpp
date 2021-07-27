#include "InteractCommandRockFloat.h"

#include "../Model/LevelModel.h"

InteractCommandRockFloat::InteractCommandRockFloat(LevelModel* model)
	: InteractCommand(model)
{
}

void InteractCommandRockFloat::setReciever(ObstacleBoardObject* reciever)
{
	this->reciever = reciever;
}

bool InteractCommandRockFloat::execute(BoardObject* initer, BoardObject* otherObj)
{
	for (int i = 0; i < this->model->getObstacles()->size(); i++)
	{
		if ((*this->model->getObstacles())[i] == otherObj)
			setReciever((*this->model->getObstacles())[i]);
	}

	//Float the reciever if not floating already
	if (reciever->isLevitating())
		return false;

	//If success float a rock, put any others that are floating down
	if (!reciever->levitateMe())
	{
		return false;
	}

	//Is leviating. Make all other object touch the ground
	std::vector<ObstacleBoardObject*>::iterator it = model->getObstacles()->begin();
	std::vector<ObstacleBoardObject*>::iterator end = model->getObstacles()->end();

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

bool InteractCommandRockFloat::needsReciever()
{
	return true;
}
