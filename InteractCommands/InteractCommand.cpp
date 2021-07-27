#include "InteractCommand.h"

#include "../Model/LevelModel.h"

InteractCommand::InteractCommand(LevelModel* model)
{
	this->model = model;
}

bool InteractCommand::needsReciever()
{
	return false;
}

bool InteractCommand::execute(BoardObject* initer, BoardObject* otherObj)
{
	return false;
}
