#include "TileBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

TileBoardObject::TileBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, false, false, action, modelKey, shaderKey)
{
}

bool TileBoardObject::needsInteractReciever()
{
	return true;
}

bool TileBoardObject::interact(BoardObject* otherObj)
{
	return false;
}


TileBoardObject* TileBoardObject::copy()
{
	return new TileBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}
