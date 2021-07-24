#include "IRendererFactory.h"

IRendererFactory::IRendererFactory(IModelFlyweightFactory* modelFactory, IShaderFlyweightFactory* shaderFactory, ISkyboxFlyweightFactory* skyboxFactory)
{
    this->modelFactory = modelFactory;
    this->shaderFactory = shaderFactory;
    this->skyboxFactory = skyboxFactory;
}

IRenderer* IRendererFactory::createRenderer(std::string key, ILevelModel* level) throw()
{
    return nullptr;
}
