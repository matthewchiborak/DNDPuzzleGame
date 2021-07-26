#include "WallBoardObject.h"

WallBoardObject::WallBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, action, modelKey, shaderKey)
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
