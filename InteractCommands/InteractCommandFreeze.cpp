#include "InteractCommandFreeze.h"

#include <iostream>

InteractCommandFreeze::InteractCommandFreeze()
{
}

bool InteractCommandFreeze::execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model)
{
	return reciever->freeze();
}
