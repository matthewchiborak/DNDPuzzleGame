#ifndef MODEL_MODIFIER_ACTION_CLASS_H
#define MODEL_MODIFIER_ACTION_CLASS_H

#include "../Model/LevelModel.h"

#include <json/json.h>

class ModelModifierAction
{
public:
	ModelModifierAction(LevelModel* level);

	virtual bool execute(nlohmann::json* message);

protected:
	LevelModel* level;
};

#endif