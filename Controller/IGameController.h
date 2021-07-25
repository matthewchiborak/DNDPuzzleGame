#ifndef I_GAME_CONTROLLER_CLASS_H
#define I_GAME_CONTROLLER_CLASS_H

class IGameStateFactory;

class IGameState;


#include <string>

#include "../Rendering/IGameWindow.h"

#include "IGameState.h"
#include "../Rendering/IRenderer.h"
#include "../Model/ILevelModel.h"

#include "../Factories/IGameStateFactory.h"
#include "../Factories/ILevelFactory.h"
#include "../Factories/IRendererFactory.h"

class IGameController
{
public:
	IGameController(
		IGameWindow * gameWindow,
		IGameStateFactory*	stateFactory,
		ILevelFactory*		levelFactory,
		IRendererFactory*	rendererFactory
		);

	virtual void start();

	virtual void setState(std::string key);
	void quit();

protected:
	IGameWindow* gameWindow;

	IGameStateFactory*	stateFactory;
	ILevelFactory*		levelFactory;
	IRendererFactory*	rendererFactory;

	IGameState*		state;
	ILevelModel*	level;
	IRenderer*		renderer;

	bool isGameRunning;
};

#endif