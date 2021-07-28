#include "ModelModifierAction.h"

ModelModifierAction::ModelModifierAction(LevelModel* level)
{
	this->level = level;
}

bool ModelModifierAction::execute(nlohmann::json* message)
{
	return false;
}
