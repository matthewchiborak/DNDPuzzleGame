#include "ObstacleBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

ObstacleBoardObject::ObstacleBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, false, action, modelKey, shaderKey)
{
}

bool ObstacleBoardObject::interact(BoardObject* otherObj)
{
	return false;
}

bool ObstacleBoardObject::needsInteractReciever()
{
	return true;
}

bool ObstacleBoardObject::push(BoardObjectAction* pushAction)
{
	this->setCurrentAction(pushAction);

	return true;
}

bool ObstacleBoardObject::levitateMe()
{
	this->leviting = true;

	return true;
}

bool ObstacleBoardObject::isLevitating()
{
	return leviting;
}

void ObstacleBoardObject::stopLevitate()
{
}
