#ifndef I_GAME_WINDOW_CLASS_H
#define I_GAME_WINDOW_CLASS_H

class GLFWwindow;

//#include<GLFW/glfw3.h>
#include "IRenderer.h"
#include "Core/Model.h"
#include "Core/ShaderSkybox.h"

class IGameWindow
{
public:
	IGameWindow(IRenderer* initialRenderer);

	void setRenderer(IRenderer* renderer);

	GLFWwindow* getWindow();
	bool shouldWindowClose();

	virtual void draw();
	virtual void clearMemory();

protected:
	GLFWwindow* window;
	IRenderer* renderer;
};

#endif