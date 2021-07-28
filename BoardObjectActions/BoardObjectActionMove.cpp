#include "BoardObjectActionMove.h"

BoardObjectActionMove::BoardObjectActionMove(BoardObject* object, int startx, int starty, int endx, int endy)
	: BoardObjectAction(object)
{
	this->startx = startx;
	this->starty = starty;
	this->endx = endx;
	this->endy = endy;
}

void BoardObjectActionMove::advance(float t)
{
	if (t > 0.5f)
		object->setPos(endx, endy);

	object->setVis(
		(((float)startx) + ((float)endx - (float)startx) * t) / 10.0f, 
		(((float)starty) + ((float)endy - (float)starty) * t) / 10.0f
	);

	if(t >= 1)
	{
		object->setVis((float)endx / 10.0f, (float)endy / 10.0f);
	}
}

BoardObjectAction* BoardObjectActionMove::copy()
{
	return new BoardObjectActionMove(this->object, this->startx, this->starty, this->endx, this->endy);
}

bool BoardObjectActionMove::nextUnchanged()
{
	return false;
}

int BoardObjectActionMove::nextPositionX()
{
	return endx;
}

int BoardObjectActionMove::nextPositionY()
{
	return endy;
}
