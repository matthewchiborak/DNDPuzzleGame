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

bool PlayerBoardObject::needsInteractReciever()
{
	return interactCommand->needsReciever();
}

InteractCommand* PlayerBoardObject::getInteractCommand()
{
	return interactCommand;
}

bool PlayerBoardObject::interact(BoardObject* otherObj)
{
	return interactCommand->execute(this, otherObj);
}
