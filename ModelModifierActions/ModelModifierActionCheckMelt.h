#ifndef MODEL_MODIFIER_ACTION_CHECK_MELT_CLASS_H
#define MODEL_MODIFIER_ACTION_CHECK_MELT_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionCheckMelt: public ModelModifierAction
{
public:
	ModelModifierActionCheckMelt(LevelModel* level);

	bool execute(nlohmann::json* message) override;
};

#endif