#ifndef GAME_STATE_STOP_CLASS_H
#define GAME_STATE_STOP_CLASS_H

#include "IGameState.h"

class GameStateStop: public IGameState
{
public:
	GameStateStop(IGameController* controller, ILevelModel* model);

	void handleUserInput(GLFWwindow* window);
	void advanceEvents();

private:
	bool buttonDown;
};

#endif