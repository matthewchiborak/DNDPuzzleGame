#ifndef RENDERER_FACTORY_CLASS_H
#define RENDERER_FACTORY_CLASS_H

#include "IRendererFactory.h"

class RendererFactory: public IRendererFactory
{
public:
	RendererFactory(
		IModelFlyweightFactory* modelFactory,
		IShaderFlyweightFactory* shaderFactory,
		ISkyboxFlyweightFactory* skyboxFactory
	);

	IRenderer* createRenderer(std::string key, ILevelModel* level) throw();
};

#endif