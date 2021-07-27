#ifndef ARROW_BOARD_OBJECT_CLASS_H
#define ARROW_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class ArrowBoardObject: public BoardObject
{
public:
	ArrowBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");

	bool interact(BoardObject* otherObj) override;
	bool needsInteractReciever() override;
};

#endif