#ifndef I_RENDERER_CLASS_H
#define I_RENDERER_CLASS_H

#include "../Model/ILevelModel.h"

#include "../Factories/IModelFlyweightFactory.h"
#include "../Factories/IShaderFlyweightFactory.h"
#include "../Factories/ISkyboxFlyweightFactory.h"

class IRenderer
{
public:
	IRenderer(
		ILevelModel*				level,
		IModelFlyweightFactory*		modelFactory,
		IShaderFlyweightFactory*	shaderFactory,
		ISkyboxFlyweightFactory*	skyboxFactory
	);

	virtual void draw(GLFWwindow* window, Camera* camera, unsigned int width, unsigned int height);

protected:
	ILevelModel*				level;
	IModelFlyweightFactory*		modelFactory;
	IShaderFlyweightFactory*	shaderFactory;
	ISkyboxFlyweightFactory*	skyboxFactory;
};

#endif