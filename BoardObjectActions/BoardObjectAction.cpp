#include "BoardObjectAction.h"

BoardObjectAction::BoardObjectAction(BoardObject* object)
{
	this->object = object;
}

BoardObjectAction* BoardObjectAction::copy()
{
	return nullptr;
}

void BoardObjectAction::advance(float t)
{
}

bool BoardObjectAction::nextUnchanged()
{
	return false;
}

int BoardObjectAction::nextPositionX()
{
	return 0;
}

int BoardObjectAction::nextPositionY()
{
	return 0;
}
