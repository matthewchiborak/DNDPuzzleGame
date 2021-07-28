#ifndef MODEL_MODIFIER_ACTION_SPACE_EXIST_CLASS_H
#define MODEL_MODIFIER_ACTION_SPACE_EXIST_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionSpaceExist: public ModelModifierAction
{
public:
	ModelModifierActionSpaceExist(LevelModel* level);

	bool execute(nlohmann::json* message) override;
};

#endif