#include "ModelModifierActionRockStop.h"

#include "../BoardObjectActions/BoardObjectActionNone.h"

ModelModifierActionRockStop::ModelModifierActionRockStop(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionRockStop::execute(nlohmann::json* message)
{
	for (int i = 0; i < this->level->getObstacles()->size(); i++)
	{
		this->level->getObstacles()->at(i)->setCurrentAction(new BoardObjectActionNone());
	}

	for (int i = 0; i < this->level->getArrows()->size(); i++)
	{
		this->level->getArrows()->at(i)->setCurrentAction(new BoardObjectActionNone());
	}

	return true;
}
