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

	//Testing
	/////////////////////
	const unsigned int width = 800;
	const unsigned int height = 800;
	// Number of samples per pixel for MSAA
	unsigned int samples = 8;

	//Keep?
	glm::vec4 lightColor;
	glm::vec3 lightPos;
	glm::mat4 lightModel;

	//Keep
	Camera camera;



};

#endif