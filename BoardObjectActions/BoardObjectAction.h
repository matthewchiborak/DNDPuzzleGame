#ifndef BOARD_OBJECT_ACTION_CLASS_H
#define BOARD_OBJECT_ACTION_CLASS_H

#include "../Model/BoardObject.h"

class BoardObjectAction
{
public:
	BoardObjectAction(BoardObject* object);

	//Will advance the action over time from 0-1
	virtual void advance(float t);

protected:
	BoardObject* object;
};

#endif