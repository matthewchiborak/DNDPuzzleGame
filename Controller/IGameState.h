#ifndef I_GAME_STATE_CLASS_H
#define I_GAME_STATE_CLASS_H

class IGameController;

#include "../Model/ILevelModel.h"
#include "IGameController.h"

//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include<glm/gtx/rotate_vector.hpp>
//#include<glm/gtx/vector_angle.hpp>

class IGameState
{
public:
	IGameState(
		IGameController* controller,
		ILevelModel* model
	);

	virtual void handleUserInput(GLFWwindow* window);
	virtual void advanceEvents();

protected:
	IGameController*	controller;
	ILevelModel*		model;
};

#endif