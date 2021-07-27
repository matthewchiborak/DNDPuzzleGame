#include "PitBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

PitBoardObject::PitBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, true, action, modelKey, shaderKey)
{
}

bool PitBoardObject::interact(BoardObject* otherObj)
{
	return false;
}

bool PitBoardObject::needsInteractReciever()
{
	return true;
}
