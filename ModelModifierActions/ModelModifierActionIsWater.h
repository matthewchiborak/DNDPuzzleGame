#ifndef MODEL_MODIFIER_ACTION_IS_WATER_CLASS_H
#define MODEL_MODIFIER_ACTION_IS_WATER_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionIsWater: public ModelModifierAction
{
public:
	ModelModifierActionIsWater(LevelModel* level);

	bool execute(nlohmann::json* message) override;
};

#endif