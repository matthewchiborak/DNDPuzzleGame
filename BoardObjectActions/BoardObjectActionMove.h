#ifndef BOARD_OBJECT_ACTION_MOVE_CLASS_H
#define BOARD_OBJECT_ACTION_MOVE_CLASS_H

#include "BoardObjectAction.h"

class BoardObjectActionMove: public BoardObjectAction
{
public:
	BoardObjectActionMove(BoardObject* object, int startx, int starty, int endx, int endy);

	void advance(float t);

private:
	int startx, starty, endx, endy;
};

#endif