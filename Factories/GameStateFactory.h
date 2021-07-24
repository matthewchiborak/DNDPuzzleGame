#ifndef GAME_STATE_FACTORY_CLASS_H
#define GAME_STATE_FACTORY_CLASS_H

#include "IGameStateFactory.h"

class GameStateFactory: public IGameStateFactory
{
public:
	GameStateFactory();

	IGameState* createState(std::string key, IGameController* controller, ILevelModel* level) throw() override;
};

#endif