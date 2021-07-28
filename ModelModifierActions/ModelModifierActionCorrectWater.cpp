#include "ModelModifierActionCorrectWater.h"

ModelModifierActionCorrectWater::ModelModifierActionCorrectWater(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionCorrectWater::execute(nlohmann::json* message)
{
	for (int i = 0; i < this->level->getWater()->size(); i++)
	{
		this->level->getWater()->at(i)->correctWaterVisual();
	}

	return false;
}
