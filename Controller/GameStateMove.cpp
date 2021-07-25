#include "GameStateMove.h"

GameStateMove::GameStateMove(IGameController* controller, ILevelModel* model)
	: IGameState(controller, model)
{
	durationMillis = 1000.0f;
	begin = std::chrono::steady_clock::now();
}

void GameStateMove::handleUserInput(GLFWwindow* window)
{
	
}

void GameStateMove::advanceEvents()
{
	std::vector<BoardObject*>::iterator it = model->getBoardObjects();
	std::vector<BoardObject*>::iterator end = model->getBoardObjectsEnd();

	std::chrono::steady_clock::time_point endt = std::chrono::steady_clock::now();

	float t = (float)std::chrono::duration_cast<std::chrono::milliseconds>(endt - begin).count() / durationMillis;

	while (it != end)
	{
		(*it)->doBoardObjectAction(t);
		it++;
	}

	if (t >= 1)
	{
		controller->setState("Stop");
	}
}
