#include "ILevelModel.h"

ILevelModel::ILevelModel()
{
}

ILevelModel::~ILevelModel()
{
    for (int i = 0; i < boardObjects.size(); i++)
    {
        delete boardObjects.at(i);
    }
}

void ILevelModel::interact()
{
}

void ILevelModel::addBoardObject(BoardObject* obj)
{
    boardObjects.push_back(obj);
}

std::vector<BoardObject*>::iterator ILevelModel::getBoardObjects()
{
    return boardObjects.begin();
}

std::vector<BoardObject*>::iterator ILevelModel::getBoardObjectsEnd()
{
    return boardObjects.end();
}

void ILevelModel::setWidth(int width)
{
    this->width = width;
}

int ILevelModel::getWidth()
{
    return width;
}

void ILevelModel::setHeight(int height)
{
    this->height = height;
}

int ILevelModel::getHeight()
{
    return height;
}
