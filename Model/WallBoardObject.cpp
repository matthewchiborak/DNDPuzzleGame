#include "WallBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

WallBoardObject::WallBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, false, action, modelKey, shaderKey)
{
}

bool WallBoardObject::needsInteractReciever()
{
	return true;
}

bool WallBoardObject::interact(BoardObject* otherObj)
{
	return false;
}
