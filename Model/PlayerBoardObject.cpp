#include "PlayerBoardObject.h"

#include <iostream>

PlayerBoardObject::PlayerBoardObject(int posX, int posY, int height, InteractCommand* iCommand, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, true, action, modelKey, shaderKey)
{
	this->interactCommand = iCommand;
}

PlayerBoardObject::~PlayerBoardObject()
{
	delete interactCommand;
}

bool PlayerBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	std::cout << "Do action " << posX << " " << posY << " " << otherObj->getPosX() << " " << otherObj->getPosY();
	return interactCommand->execute(this, otherObj, model);
}
