#include "LevelModel.h"

#include <iostream>

LevelModel::LevelModel()
	: ILevelModel()
{

}

void LevelModel::interact()
{
	std::cout << "Interact called in level model";
}
