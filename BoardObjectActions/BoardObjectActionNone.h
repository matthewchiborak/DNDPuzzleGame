#ifndef BOARD_OBJECT_ACTION_NONE_CLASS_H
#define BOARD_OBJECT_ACTION_NONE_CLASS_H

#include "BoardObjectAction.h"

class BoardObjectActionNone: public BoardObjectAction
{
public:
	BoardObjectActionNone();

	void advance(float t);
	BoardObjectAction* copy();

};

#endif