#include "ObstacleBoardObject.h"

ObstacleBoardObject::ObstacleBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, action, modelKey, shaderKey)
{
}

bool ObstacleBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

bool ObstacleBoardObject::push(BoardObjectAction* pushAction)
{
	this->setCurrentAction(pushAction);

	return true;
}
