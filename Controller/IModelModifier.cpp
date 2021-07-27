#include "IModelModifier.h"

IModelModifier::IModelModifier()
{
	
}

void IModelModifier::setLevel(LevelModel* level)
{
	this->level = level;
}

bool IModelModifier::modify(std::string key)
{
	return false;
}
