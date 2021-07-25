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
		level = levelFactory->createLevel("1");
	}
	catch (int e) {
		quit();
	}

	try {
		lastStateKey = "Stop";
		state = stateFactory->createState("Stop", this, level);
	}
	catch (std::string e) {
		quit();
	}

	try {
		lastRendererKey = "Board";
		renderer = rendererFactory->createRenderer("Board", level);
		gameWindow->setRenderer(renderer);
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
		state->advanceEvents();
		state->handleUserInput(gameWindow->getWindow());
		gameWindow->draw();
	}

	gameWindow->clearMemory();

	if (renderer != nullptr)
		delete renderer;
	if (level != nullptr)
		delete level;
	if (state != nullptr)
		delete state;

}

void GameController::setState(std::string key)
{
	if (key == lastStateKey)
		return;

	lastStateKey = key;

	IGameState* temp = state;
	state = stateFactory->createState(key, this, level);
	delete temp;
}
