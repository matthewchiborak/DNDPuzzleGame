#include "WallBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

WallBoardObject::WallBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, false, action, modelKey, shaderKey)
{
}

bool WallBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool WallBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

bool WallBoardObject::levitateMe()
{
	return false;
}

BoardObject* WallBoardObject::copy()
{
	return new WallBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}
