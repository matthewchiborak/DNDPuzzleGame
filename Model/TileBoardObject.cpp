#include "TileBoardObject.h"

TileBoardObject::TileBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, action, modelKey, shaderKey)
{
}

void TileBoardObject::interact(BoardObject* otherObj)
{
}
