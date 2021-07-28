#ifndef MODEL_MODIFIER_ACTION_CORRECT_WATER_CLASS_H
#define MODEL_MODIFIER_ACTION_CORRECT_WATER_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionCorrectWater: public ModelModifierAction
{
public:
	ModelModifierActionCorrectWater(LevelModel* level);

	bool execute(nlohmann::json* message) override;
};

#endif