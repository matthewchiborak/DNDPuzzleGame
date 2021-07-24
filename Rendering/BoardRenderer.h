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

	void draw(GLFWwindow* window, Camera* camera) override;

	void createSkybox();

private:
	double prevTime;
	double crntTime;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter;

	//Trying something
	unsigned int skyboxVAO, skyboxVBO, skyboxEBO;
	unsigned int cubemapTexture;
	bool skyboxInited = false;
};

#endif