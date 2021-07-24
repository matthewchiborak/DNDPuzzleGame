#include "IGameState.h"

IGameState::IGameState(IGameController* controller, ILevelModel* model)
{
	this->controller = controller;
	this->model = model;
}

void IGameState::handleUserInput(GLFWwindow* window)
{
}
