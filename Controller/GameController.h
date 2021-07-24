#ifndef GAME_CONTROLLER_CLASS_H
#define GAME_CONTROLLER_CLASS_H

#include "IGameController.h"

class GameController: public IGameController
{
public:
	GameController(
		IGameWindow* gameWindow,
		IGameStateFactory* stateFactory,
		ILevelFactory* levelFactory,
		IRendererFactory* rendererFactory
	);

	void start() override;

};

#endif