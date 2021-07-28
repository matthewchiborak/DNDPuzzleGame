#ifndef MODEL_MODIFIER_ACTION_ROCK_STOP_CLASS_H
#define MODEL_MODIFIER_ACTION_ROCK_STOP_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionRockStop: public ModelModifierAction
{
public:
	ModelModifierActionRockStop(LevelModel* level);

	bool execute(nlohmann::json* message) override;
};

#endif