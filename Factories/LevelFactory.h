#ifndef LEVEL_FACTORY_CLASS_H
#define LEVEL_FACTORY_CLASS_H

#include "ILevelFactory.h"

#include <json/json.h>

#include "../InteractCommands/InteractCommand.h"

#include "../BoardObjectActions/BoardObjectAction.h"

class LevelFactory: public ILevelFactory
{
public:
	LevelFactory();

	ILevelModel* createLevel(std::string key) throw() override;

private:
	InteractCommand* createInteractCommand(std::string key, LevelModel* level, nlohmann::json JSON);
	BoardObjectAction* createBoardObjectAction(std::string key, BoardObject* object);
};

#endif