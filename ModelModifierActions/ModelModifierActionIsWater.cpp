#include "ModelModifierActionIsWater.h"

ModelModifierActionIsWater::ModelModifierActionIsWater(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionIsWater::execute(nlohmann::json* message)
{
	for (int i = 0; i < this->level->getWater()->size(); i++)
	{
		if (this->level->getWater()->at(i)->getPosX() == (*message)["X"] && this->level->getWater()->at(i)->getPosY() == (*message)["Y"])
		{
			return true;
		}
	}

	return false;
}
