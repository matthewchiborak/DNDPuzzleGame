#include "GameStateStop.h"

GameStateStop::GameStateStop(IGameController* controller, ILevelModel* model)
	: IGameState(controller, model)
{
	buttonDown = false;
}

void GameStateStop::handleUserInput(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		if(model->playerMove(0, 1))
			controller->setState("Move");
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		if(model->playerMove(-1, 0))
			controller->setState("Move");
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		if(model->playerMove(0, -1))
			controller->setState("Move");
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		if(model->playerMove(1, 0))
			controller->setState("Move");
	}
	else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model->playerChange(false);
			buttonDown = true;
		}

		return;
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model->playerChange(true);
			buttonDown = true;
		}

		return;
	}
	else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		if(model->interact())
			controller->setState("Move");
	}

	buttonDown = false;
}

void GameStateStop::advanceEvents()
{
}
