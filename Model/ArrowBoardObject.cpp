#include "ArrowBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

ArrowBoardObject::ArrowBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, false, action, modelKey, shaderKey)
{
}

BoardObject* ArrowBoardObject::copy()
{
	return new ArrowBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}

bool ArrowBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool ArrowBoardObject::needsInteractReciever()
{
	return false;
}

bool ArrowBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

bool ArrowBoardObject::levitateMe()
{
	return false;
}

bool ArrowBoardObject::freeze()
{
	return false;
}

bool ArrowBoardObject::melt()
{
	return false;
}

void ArrowBoardObject::correctWaterVisual()
{
}
