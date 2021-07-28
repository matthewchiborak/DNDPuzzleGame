#ifndef MODEL_MODIFIER_ACTION_IS_PIT_CLASS_H
#define MODEL_MODIFIER_ACTION_IS_PIT_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionIsPit: public ModelModifierAction
{
public:
	ModelModifierActionIsPit(LevelModel* level);

	bool execute(nlohmann::json* message) override;
};

#endif