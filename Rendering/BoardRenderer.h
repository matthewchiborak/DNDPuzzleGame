#ifndef BOARD_RENDERER_CLASS_H
#define BOARD_RENDERER_CLASS_H

#include "IRenderer.h"

class BoardRenderer: public IRenderer
{
public:
	BoardRenderer(
		ILevelModel* level,
		IModelFlyweightFactory* modelFactory,
		IShaderFlyweightFactory* shaderFactory,
		ISkyboxFlyweightFactory* skyboxFactory
	);

	void draw(GLFWwindow* window, Camera* camera, unsigned int width, unsigned int height) override;

private:
	double prevTime;
	double crntTime;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter;

	//The skybox will have to live here until I figure out why the skybox factory isn't working
	unsigned int skyboxVAO, skyboxVBO, skyboxEBO;
	unsigned int cubemapTexture;
	bool skyboxInited = false;

	void createSkybox();
	void drawFPS(GLFWwindow* window);
	void clearScreen();
	void updateCamera(Camera* camera);
	void drawScene(Camera* camera);
	void drawSkybox(Camera* camera, unsigned int windowWidth, unsigned int windowHeight);
};

#endif