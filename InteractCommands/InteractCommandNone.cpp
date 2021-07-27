#include "InteractCommandNone.h"

InteractCommandNone::InteractCommandNone()
	: InteractCommand(nullptr)
{
}

bool InteractCommandNone::execute(BoardObject* initer, BoardObject* otherObj)
{
	return false;
}

bool InteractCommandNone::needsReciever()
{
	return false;
}
