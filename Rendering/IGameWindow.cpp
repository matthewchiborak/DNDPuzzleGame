#include "IGameWindow.h"

IGameWindow::IGameWindow(IRenderer* initialRenderer)
{
	this->renderer = initialRenderer;
}

void IGameWindow::setRenderer(IRenderer* renderer)
{
	IRenderer* temp = this->renderer;
	this->renderer = renderer;
	delete temp;
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
