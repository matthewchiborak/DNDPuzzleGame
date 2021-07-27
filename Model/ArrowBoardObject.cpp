#include "ArrowBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

ArrowBoardObject::ArrowBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, false, action, modelKey, shaderKey)
{
}

bool ArrowBoardObject::interact(BoardObject* otherObj)
{
	return false;
}

bool ArrowBoardObject::needsInteractReciever()
{
	return false;
}


