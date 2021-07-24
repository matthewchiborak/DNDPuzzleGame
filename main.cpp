
#include "Controller/GameController.h"

#include "Rendering/GameWindow.h"

#include "Factories/GameStateFactory.h"
#include "Factories/LevelFactory.h"
#include "Factories/RendererFactory.h"

int main()
{
	IGameStateFactory* gameStateFactory = new GameStateFactory();
	ILevelFactory* levelFactory = new LevelFactory();
	IRendererFactory* rendererFactory = new RendererFactory();

	IGameWindow* gameWindow = new GameWindow(rendererFactory->createRenderer("Board"));

	IGameController * controller = new GameController(gameWindow, gameStateFactory, levelFactory, rendererFactory);

	controller->start();

	delete controller;
	delete gameStateFactory;
	delete rendererFactory;
	delete levelFactory;
	
	return 0;
}