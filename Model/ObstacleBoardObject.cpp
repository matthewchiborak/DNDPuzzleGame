#include "ObstacleBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

ObstacleBoardObject::ObstacleBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, false, action, modelKey, shaderKey)
{
}

BoardObject* ObstacleBoardObject::copy()
{
	return new ObstacleBoardObject(posX, posY, height, currentAction->copy(), modelKey, shaderKey);
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

bool ObstacleBoardObject::levitateMe()
{
	this->leviting = true;

	return true;
}
