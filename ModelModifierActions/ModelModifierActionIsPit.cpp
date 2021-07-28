#include "ModelModifierActionIsPit.h"

ModelModifierActionIsPit::ModelModifierActionIsPit(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionIsPit::execute(nlohmann::json* message)
{
	for (int i = 0; i < this->level->getPits()->size(); i++)
	{
		if (this->level->getPits()->at(i)->getPosX() == (*message)["X"] && this->level->getPits()->at(i)->getPosY() == (*message)["Y"])
		{
			return true;
		}
	}

	return false;
}
