#ifndef TILE_BOARD_OBJECT_CLASS_H
#define TILE_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class TileBoardObject: public BoardObject
{
public:
	TileBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Default");

	bool needsInteractReciever() override;
	bool interact(BoardObject* otherObj) override;

	TileBoardObject* copy();
};

#endif