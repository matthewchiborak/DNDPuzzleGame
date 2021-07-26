#include "PlayerBoardObject.h"

#include <iostream>

PlayerBoardObject::PlayerBoardObject(int posX, int posY, int height, InteractCommand* iCommand, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, true, action, modelKey, shaderKey)
{
	this->interactCommand = iCommand;
}

PlayerBoardObject::~PlayerBoardObject()
{
	delete interactCommand;
}

bool PlayerBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return interactCommand->execute(this, otherObj, model);
}

bool PlayerBoardObject::push(BoardObjectAction* pushAction)
{
	return false;
}

bool PlayerBoardObject::levitateMe()
{
	return false;
}

BoardObject* PlayerBoardObject::copy()
{
	return nullptr;
}
