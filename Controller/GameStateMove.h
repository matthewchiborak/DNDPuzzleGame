#ifndef GAME_STATE_MOVE_CLASS_H
#define GAME_STATE_MOVE_CLASS_H

#include "IGameState.h"

class GameStateMove: public IGameState
{
public:
	GameStateMove(IGameController* controller, ILevelModel* model);

	void handleUserInput(GLFWwindow* window);
};

#endif