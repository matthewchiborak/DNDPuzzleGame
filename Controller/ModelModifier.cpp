#include "ModelModifier.h"

#include <iostream>

ModelModifier::ModelModifier()
	: IModelModifier()
{
}

bool ModelModifier::modify(std::string key)
{
	std::cout << "Time to modify " << key << "\n";
	return false;
}
