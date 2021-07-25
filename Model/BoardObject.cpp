#include "BoardObject.h"

#include "../BoardObjectActions/BoardObjectAction.h"

BoardObject::BoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey)
{
	this->posX = posX;
	this->posY = posY;
	this->visX = ((float)posX)/10.0f;
	this->visY = ((float)posY)/10.0f;
	this->height = height;
	this->modelKey = modelKey;
	this->shaderKey = shaderKey;
	this->currentAction = action;
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

void BoardObject::interact(BoardObject* otherObj)
{
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

std::string BoardObject::getModelKey()
{
	return modelKey;
}

std::string BoardObject::getShaderKey()
{
	return shaderKey;
}
