#include "WaterBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

WaterBoardObject::WaterBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, true, action, modelKey, shaderKey)
{
}

bool WaterBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool WaterBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

bool WaterBoardObject::levitateMe()
{
	return false;
}

BoardObject* WaterBoardObject::copy()
{
	return new WaterBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}
