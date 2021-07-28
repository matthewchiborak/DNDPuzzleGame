#include "BoardObjectActionNone.h"

BoardObjectActionNone::BoardObjectActionNone()
	: BoardObjectAction(nullptr)
{
}

void BoardObjectActionNone::advance(float t)
{
}

BoardObjectAction* BoardObjectActionNone::copy()
{
	return new BoardObjectActionNone();
}

bool BoardObjectActionNone::nextUnchanged()
{
	return true;
}

int BoardObjectActionNone::nextPositionX()
{
	return 0;
}

int BoardObjectActionNone::nextPositionY()
{
	return 0;
}
