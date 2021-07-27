#ifndef WATER_BOARD_OBJECT_CLASS_H
#define WATER_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class WaterBoardObject: public BoardObject
{
public:
	WaterBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string modelKeyFreeze, std::string shaderKey = "Default");

	bool needsInteractReciever() override;
	bool interact(BoardObject* otherObj) override;
	bool freeze();
	bool melt();
	void correctWaterVisual();

private:
	std::string modelKeyFreeze;
	std::string modelKeyLiquid;
};

#endif