#ifndef BOARD_OBJECT_ACTION_MOVE_CONTINUOUS_CLASS_H
#define BOARD_OBJECT_ACTION_MOVE_CONTINUOUS_CLASS_H

#include "BoardObjectAction.h"

class BoardObjectActionMoveContinuous: public BoardObjectAction
{
public:
	BoardObjectActionMoveContinuous(BoardObject* object, int startx, int starty, int dirx, int diry);

	void advance(float t) override;
	BoardObjectAction* copy() override;

	bool nextUnchanged() override;
	int nextPositionX() override;
	int nextPositionY() override;

private:
	int startx, starty, endx, endy;
};

#endif