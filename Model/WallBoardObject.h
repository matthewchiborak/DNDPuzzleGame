#ifndef WALL_BOARD_OBJECT_CLASS_H
#define WALL_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class WallBoardObject: public BoardObject
{
public:
	WallBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Default");

	bool needsInteractReciever() override;
	bool interact(BoardObject* otherObj) override;

};

#endif