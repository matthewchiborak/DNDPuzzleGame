#include "RendererFactory.h"

#include "../Rendering/BoardRenderer.h"

RendererFactory::RendererFactory(IModelFlyweightFactory* modelFactory, IShaderFlyweightFactory* shaderFactory, ISkyboxFlyweightFactory* skyboxFactory)
	: IRendererFactory(modelFactory, shaderFactory, skyboxFactory)
{
}

IRenderer* RendererFactory::createRenderer(std::string key, ILevelModel* level) throw()
{
	if (key == "Board")
		return new BoardRenderer(level, modelFactory, shaderFactory, skyboxFactory);

	throw(key);
}
