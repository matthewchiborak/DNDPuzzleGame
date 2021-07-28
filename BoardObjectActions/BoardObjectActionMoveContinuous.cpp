#include "BoardObjectActionMoveContinuous.h"

BoardObjectActionMoveContinuous::BoardObjectActionMoveContinuous(BoardObject* object, int startx, int starty, int dirx, int diry)
	: BoardObjectAction(object)
{
	this->startx = startx;
	this->starty = starty;
	this->endx = startx + dirx;
	this->endy = starty + diry;
}

void BoardObjectActionMoveContinuous::advance(float t)
{
	if (t > 0.5f)
		object->setPos(endx, endy);

	object->setVis(
		(((float)startx) + ((float)endx - (float)startx) * t) / 10.0f,
		(((float)starty) + ((float)endy - (float)starty) * t) / 10.0f
	);

	if (t >= 1)
	{
		object->setVis((float)endx / 10.0f, (float)endy / 10.0f);

		//Make it continuous
		int dirX = endx - startx;
		int dirY = endy - starty;
		startx = endx;
		starty = endy;
		endx += dirX;
		endy += dirY;
	}
}

BoardObjectAction* BoardObjectActionMoveContinuous::copy()
{
	return new BoardObjectActionMoveContinuous(object, startx, starty, endx, endy);
}

bool BoardObjectActionMoveContinuous::nextUnchanged()
{
	return false;
}

int BoardObjectActionMoveContinuous::nextPositionX()
{
	return endx;
}

int BoardObjectActionMoveContinuous::nextPositionY()
{
	return endy;
}
