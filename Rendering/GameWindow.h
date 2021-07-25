#ifndef GAME_WINDOW_CLASS_H
#define GAME_WINDOW_CLASS_H

#include "IGameWindow.h"

#include <vector>

class GameWindow: public IGameWindow
{
public:
	GameWindow(IRenderer* initialRenderer);

	void draw() override;
	void clearMemory() override;

private:
	void setUp();

	const unsigned int width = 1600;
	const unsigned int height = 900;
	// Number of samples per pixel for MSAA
	unsigned int samples = 8;

	//Keep
	Camera camera;

};

#endif