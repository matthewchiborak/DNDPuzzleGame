#include "IGameWindow.h"

IGameWindow::IGameWindow(IRenderer* initialRenderer)
{
	setRenderer(initialRenderer);
}

void IGameWindow::setRenderer(IRenderer* renderer)
{
	this->renderer = renderer;
}

GLFWwindow* IGameWindow::getWindow()
{
	return window;
}

bool IGameWindow::shouldWindowClose()
{
	return glfwWindowShouldClose(window);
}

void IGameWindow::draw()
{
}

void IGameWindow::clearMemory()
{
}
