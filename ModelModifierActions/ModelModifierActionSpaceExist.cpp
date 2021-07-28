#include "ModelModifierActionSpaceExist.h"

ModelModifierActionSpaceExist::ModelModifierActionSpaceExist(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionSpaceExist::execute(nlohmann::json* message)
{
	for (int i = 0; i < this->level->getTiles()->size(); i++)
	{
		if (this->level->getTiles()->at(i)->getPosX() == (*message)["X"] && this->level->getTiles()->at(i)->getPosY() == (*message)["Y"])
		{
			return true;
		}
	}

	return false;
}
