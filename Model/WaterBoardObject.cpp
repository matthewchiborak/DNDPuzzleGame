#include "WaterBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

WaterBoardObject::WaterBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string modelKeyFreeze, std::string shaderKey)
	: BoardObject(posX, posY, height, true, true, action, modelKey, shaderKey)
{
	this->modelKeyFreeze = modelKeyFreeze;
	this->modelKeyLiquid = modelKey;
}

bool WaterBoardObject::needsInteractReciever()
{
	return true;
}

bool WaterBoardObject::interact(BoardObject* otherObj)
{
	return false;
}

bool WaterBoardObject::freeze()
{
	if (!isSolid())
		return false;

	modelKey = modelKeyFreeze;

	this->solid = false;
	return true;
}

bool WaterBoardObject::melt()
{
	if (isSolid())
		return false;

	this->solid = true;
	return true;
}

void WaterBoardObject::correctWaterVisual()
{
	if (isSolid())
	{
		modelKey = modelKeyLiquid;
	}
}

