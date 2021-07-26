#include "BoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"


BoardObject::BoardObject(int posX, int posY, int height, bool solid, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
{
	this->posX = posX;
	this->posY = posY;
	this->visX = ((float)posX)/10.0f;
	this->visY = ((float)posY)/10.0f;
	this->height = height;
	this->modelKey = modelKey;
	this->shaderKey = shaderKey;
	this->currentAction = action;
	this->lastDirMovedx = 1;
	this->lastDirMovedy = 0;
	this->solid = solid;
}

void BoardObject::setCurrentAction(BoardObjectAction* action)
{
	BoardObjectAction* temp = this->currentAction;
	this->currentAction = action;
	delete temp;
}

void BoardObject::doBoardObjectAction(float t)
{
	this->currentAction->advance(t);
}

void BoardObject::move(int x, int y)
{
	this->posX += x;
	this->posY += y;
}

bool BoardObject::interact(BoardObject* otherObj, ILevelModel* model)
{
	return false;
}

void BoardObject::setPos(int x, int y)
{
	this->posX = x;
	this->posY = y;
}

void BoardObject::setVis(float x, float y)
{
	this->visX = x;
	this->visY = y;
}

void BoardObject::setLastDirMoved(int x, int y)
{
	this->lastDirMovedx = x;
	this->lastDirMovedy = y;
}

int BoardObject::getPosX()
{
	return posX;
}

int BoardObject::getPosY()
{
	return posY;
}

float BoardObject::getVisX()
{
	return visX;
}

float BoardObject::getVisY()
{
	return visY;
}

int BoardObject::getHeight()
{
	return height;
}

int BoardObject::getLastDirMovedX()
{
	return lastDirMovedx;
}

int BoardObject::getLastDirMovedY()
{
	return lastDirMovedy;
}

std::string BoardObject::getModelKey()
{
	return modelKey;
}

std::string BoardObject::getShaderKey()
{
	return shaderKey;
}

bool BoardObject::isSolid()
{
	return solid;
}
