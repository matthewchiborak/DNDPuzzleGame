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
