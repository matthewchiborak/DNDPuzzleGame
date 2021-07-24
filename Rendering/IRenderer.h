#ifndef I_RENDERER_CLASS_H
#define I_RENDERER_CLASS_H

class GLFWwindow;

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

	virtual void draw(GLFWwindow* window, Camera* camera);

protected:
	ILevelModel*				level;
	IModelFlyweightFactory*		modelFactory;
	IShaderFlyweightFactory*	shaderFactory;
	ISkyboxFlyweightFactory*	skyboxFactory;
};

#endif