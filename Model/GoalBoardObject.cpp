
#include "../BoardObjectActions/BoardObjectAction.h"
#include "GoalBoardObject.h"



GoalBoardObject::GoalBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, false, false, action, modelKey, shaderKey)
{
}

GoalBoardObject::~GoalBoardObject()
{
}

bool GoalBoardObject::needsInteractReciever()
{
	return false;
}

bool GoalBoardObject::interact(BoardObject* otherObj)
{
	return false;
}
