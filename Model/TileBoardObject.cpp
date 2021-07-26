#include "TileBoardObject.h"

TileBoardObject::TileBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
	: BoardObject(posX, posY, height, false, action, modelKey, shaderKey)
{
}

bool TileBoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}
