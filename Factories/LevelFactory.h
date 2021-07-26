#ifndef LEVEL_FACTORY_CLASS_H
#define LEVEL_FACTORY_CLASS_H

#include "ILevelFactory.h"

#include "../InteractCommands/InteractCommand.h"

class LevelFactory: public ILevelFactory
{
public:
	LevelFactory();

	ILevelModel* createLevel(std::string key) throw() override;

private:
	InteractCommand* createInteractCommand(std::string key);
};

#endif