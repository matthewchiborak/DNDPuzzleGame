#include "GameController.h"

#include <iostream>

GameController::GameController(IGameWindow* gameWindow, IGameStateFactory* stateFactory, ILevelFactory* levelFactory, IRendererFactory* rendererFactory)
	: IGameController(gameWindow, stateFactory, levelFactory, rendererFactory)
{
	level = nullptr;
	state = nullptr;
	renderer = nullptr;

	//Have the factories create the inital state of the game
	try {
		level = levelFactory->createLevel(1);
	}
	catch (int e) {
		quit();
	}

	try {
		state = stateFactory->createState("Stop", this, level);
	}
	catch (std::string e) {
		quit();
	}

	try {
		renderer = rendererFactory->createRenderer("Board");
	}
	catch (std::string e) {
		quit();
	}
}

void GameController::start()
{
	//while (isGameRunning)
	while (!gameWindow->shouldWindowClose())
	{
		gameWindow->draw();
	}

	gameWindow->clearMemory();

	if (level != nullptr)
		delete level;
	if (state != nullptr)
		delete state;
	if (renderer != nullptr)
		delete renderer;
}
