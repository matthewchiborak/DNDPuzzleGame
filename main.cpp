
#include "Controller/GameController.h"

#include "Rendering/GameWindow.h"

#include "Factories/ModelFlyweightFactory.h"
#include "Factories/ShaderFlyweightFactory.h"
#include "Factories/SkyboxFlyweightFactory.h"

#include "Factories/GameStateFactory.h"
#include "Factories/LevelFactory.h"
#include "Factories/RendererFactory.h"

int main()
{
	IModelFlyweightFactory* modelFactory = new ModelFlyweightFactory();
	IShaderFlyweightFactory* shaderFactory = new ShaderFlyweightFactory();
	ISkyboxFlyweightFactory* skyboxFactory = new SkyboxFlyweightFactory();

	IGameStateFactory* gameStateFactory = new GameStateFactory();
	ILevelFactory* levelFactory = new LevelFactory();
	IRendererFactory* rendererFactory = new RendererFactory(modelFactory, shaderFactory, skyboxFactory);

	IGameWindow* gameWindow = new GameWindow(rendererFactory->createRenderer("Board", levelFactory->createLevel("-1")));

	IGameController * controller = new GameController(gameWindow, gameStateFactory, levelFactory, rendererFactory);

	controller->start();

	delete controller;
	delete gameStateFactory;
	delete rendererFactory;
	delete levelFactory;
	
	return 0;
}