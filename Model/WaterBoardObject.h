#ifndef WATER_BOARD_OBJECT_CLASS_H
#define WATER_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class WaterBoardObject: public BoardObject
{
public:
	WaterBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Default");

	bool interact(BoardObject* otherObj, ILevelModel* model) override;
	bool push(BoardObjectAction* pushAction) override;
	bool levitateMe() override;

	BoardObject* copy() override;

};

#endif