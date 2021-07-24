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

	//std::vector<float> skyboxVertices;
	//std::vector<unsigned int> skyboxIndices;

	Shader shaderProgram;
	Shader grassProgram;
	ShaderSkybox skyboxShader;

	glm::vec4 lightColor;
	glm::vec3 lightPos;
	glm::mat4 lightModel;

	Camera camera;

	Model model;
	Model grass;

	double prevTime;
	double crntTime;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter;

	unsigned int skyboxVAO, skyboxVBO, skyboxEBO;

	std::string facesCubemap[6];

	unsigned int cubemapTexture;
};

#endif