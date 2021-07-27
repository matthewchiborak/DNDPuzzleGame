#include "InteractCommand.h"

InteractCommand::InteractCommand()
{
}

bool InteractCommand::needsReciever()
{
	return false;
}

bool InteractCommand::execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model)
{
	return false;
}
