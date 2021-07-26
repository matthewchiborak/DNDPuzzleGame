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
