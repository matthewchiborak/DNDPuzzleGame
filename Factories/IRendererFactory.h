#ifndef I_RENDERER_FACTORY_CLASS_H
#define I_RENDERER_FACTORY_CLASS_H

#include <string>

#include "../Rendering/IRenderer.h"

class IRendererFactory
{
public:
	IRendererFactory(
		IModelFlyweightFactory* modelFactory,
		IShaderFlyweightFactory* shaderFactory,
		ISkyboxFlyweightFactory* skyboxFactory
	);

	virtual IRenderer* createRenderer(std::string key, ILevelModel* level) throw();

protected:
	IModelFlyweightFactory* modelFactory;
	IShaderFlyweightFactory* shaderFactory;
	ISkyboxFlyweightFactory* skyboxFactory;
};

#endif