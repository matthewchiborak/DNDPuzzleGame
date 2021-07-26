#include "PitBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

PitBoardObject::PitBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, true, action, modelKey, shaderKey)
{
}

bool PitBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool PitBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

bool PitBoardObject::levitateMe()
{
	return false;
}

BoardObject* PitBoardObject::copy()
{
	return new PitBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
}
