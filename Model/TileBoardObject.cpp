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

bool TileBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool TileBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

bool TileBoardObject::levitateMe()
{
	return false;
}

bool TileBoardObject::freeze()
{
	return false;
}

bool TileBoardObject::melt()
{
	return false;
}

void TileBoardObject::correctWaterVisual()
{
}

BoardObject* TileBoardObject::copy()
{
	return new TileBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}
