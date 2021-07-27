#include "InteractCommandNone.h"

InteractCommandNone::InteractCommandNone()
{
}

bool InteractCommandNone::execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model)
{
	return false;
}

bool InteractCommandNone::needsReciever()
{
	return true;
}
