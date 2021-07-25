#include "PlayerBoardObject.h"

#include <iostream>

PlayerBoardObject::PlayerBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, action, modelKey, shaderKey)
{
}

void PlayerBoardObject::interact(BoardObject* otherObj)
{
	//TODO
	//interactCommand.execute() or w/e
	std::cout << "Do action\n";
}
