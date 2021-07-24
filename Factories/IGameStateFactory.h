#ifndef I_GAME_STATE_FACTORY_CLASS_H
#define I_GAME_STATE_FACTORY_CLASS_H

#include <string>
#include <iostream>
#include "../Controller/IGameState.h"

#include "../Controller/IGameController.h"
#include "../Model/ILevelModel.h"

class IGameStateFactory
{
public:
	IGameStateFactory();

	virtual IGameState* createState(std::string key, IGameController* controller, ILevelModel* level) throw();
};

#endif