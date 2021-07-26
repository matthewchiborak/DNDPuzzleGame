#include "TileBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

TileBoardObject::TileBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, false, false, action, modelKey, shaderKey)
{
}

bool TileBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool TileBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

BoardObject* TileBoardObject::copy()
{
	return new TileBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}
