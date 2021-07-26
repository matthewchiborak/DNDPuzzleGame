#ifndef WALL_BOARD_OBJECT_CLASS_H
#define WALL_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class WallBoardObject: public BoardObject
{
public:
	WallBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Default");

	bool interact(BoardObject* otherObj, ILevelModel* model) override;

	bool push(BoardObjectAction* pushAction) override;

	BoardObject* copy() override;
};

#endif