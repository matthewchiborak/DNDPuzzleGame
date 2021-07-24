#ifndef LEVEL_FACTORY_CLASS_H
#define LEVEL_FACTORY_CLASS_H

#include "ILevelFactory.h"

class LevelFactory: public ILevelFactory
{
public:
	LevelFactory();

	ILevelModel* createLevel(int levelNo) const throw() override;
};

#endif