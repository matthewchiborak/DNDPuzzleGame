#ifndef WATER_BOARD_OBJECT_CLASS_H
#define WATER_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class WaterBoardObject: public BoardObject
{
public:
	WaterBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string modelKeyFreeze, std::string shaderKey = "Default");

	bool interact(BoardObject* otherObj, ILevelModel* model) override;
	bool push(BoardObjectAction* pushAction) override;
	bool levitateMe() override;
	bool freeze() override;
	bool melt() override;
	void correctWaterVisual() override;

	BoardObject* copy() override;

private:
	std::string modelKeyFreeze;
	std::string modelKeyLiquid;
};

#endif