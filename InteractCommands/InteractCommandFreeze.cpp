#include "InteractCommandFreeze.h"

#include "../Model/LevelModel.h"

InteractCommandFreeze::InteractCommandFreeze(LevelModel* model)
	: InteractCommand(model)
{
}

void InteractCommandFreeze::setReciever(WaterBoardObject* reciever)
{
	this->reciever = reciever;
}

bool InteractCommandFreeze::execute(BoardObject* initer, BoardObject* otherObj)
{
	for (int i = 0; i < this->model->getWater()->size(); i++)
	{
		if ((*this->model->getWater())[i] == otherObj)
			setReciever((*this->model->getWater())[i]);
	}

	return reciever->freeze();
}

bool InteractCommandFreeze::needsReciever()
{
	return true;
}
