#include "BoardObject.h"

BoardObject::BoardObject(int posX, int posY, int height, std::string modelKey, std::string shaderKey)
{
	this->posX = posX;
	this->posY = posY;
	this->height = height;
	this->modelKey = modelKey;
	this->shaderKey = shaderKey;
}

void BoardObject::move(int x, int y)
{
	this->posX += x;
	this->posY += y;
}

void BoardObject::interact(BoardObject* otherObj)
{
}

int BoardObject::getPosX()
{
	return posX;
}

int BoardObject::getPosY()
{
	return posY;
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
