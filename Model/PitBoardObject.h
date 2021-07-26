#ifndef PIT_BOARD_OBJECT_CLASS_H
#define PIT_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class PitBoardObject: public BoardObject
{
public:
	PitBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Default");

	bool interact(BoardObject* otherObj, ILevelModel* model) override;
	bool push(BoardObjectAction* pushAction) override;

	BoardObject* copy() override;

};

#endif