#include "IGameController.h"

IGameController::IGameController(IGameWindow* gameWindow, IGameStateFactory* stateFactory, ILevelFactory* levelFactory, IRendererFactory* rendererFactory)
{
	isGameRunning = true;

	this->gameWindow = gameWindow;
	this->stateFactory = stateFactory;
	this->levelFactory = levelFactory;
	this->rendererFactory = rendererFactory;
}

void IGameController::start()
{
}

void IGameController::setState(std::string key)
{
}

void IGameController::quit()
{
	isGameRunning = false;
}
