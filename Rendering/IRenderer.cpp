#include "IRenderer.h"

IRenderer::IRenderer(ILevelModel* level, IModelFlyweightFactory* modelFactory, IShaderFlyweightFactory* shaderFactory, ISkyboxFlyweightFactory* skyboxFactory)
{
	this->level = level;
	this->modelFactory = modelFactory;
	this->shaderFactory = shaderFactory;
	this->skyboxFactory = skyboxFactory;
}

void IRenderer::draw(GLFWwindow* window, Camera* camera, unsigned int width, unsigned int height)
{
}
