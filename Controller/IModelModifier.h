#ifndef I_MODEL_MODIFIER_CLASS_H
#define I_MODEL_MODIFIER_CLASS_H

#include <vector>

#include "../Model/LevelModel.h"

#include <json/json.h>

class IModelModifier
{
public:
	IModelModifier();

	void setLevel(LevelModel* level);

	virtual bool modify(std::string message);

protected:
	LevelModel* level;
};

#endif