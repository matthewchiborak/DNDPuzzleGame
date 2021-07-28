
#include "EnemyBoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

EnemyBoardObject::EnemyBoardObject(int posX, int posY, int height, bool squishy, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, squishy, action, modelKey, shaderKey)
{
}

EnemyBoardObject::~EnemyBoardObject()
{
}

bool EnemyBoardObject::needsInteractReciever()
{
	return false;
}

bool EnemyBoardObject::interact(BoardObject* otherObj)
{
	return false;
}

int EnemyBoardObject::getNextXPos()
{
	if (currentAction->nextUnchanged())
		return posX;

	return currentAction->nextPositionX();
}

int EnemyBoardObject::getNextYPos()
{
	if (currentAction->nextUnchanged())
		return posY;

	return currentAction->nextPositionY();
}
