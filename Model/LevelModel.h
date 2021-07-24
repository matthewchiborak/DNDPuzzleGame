#ifndef LEVEL_MODEL_CLASS_H
#define LEVEL_MODEL_CLASS_H

#include "ILevelModel.h"

class LevelModel: public ILevelModel
{
public:
	LevelModel();

	void interact() override;
};

#endif