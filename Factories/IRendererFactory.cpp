#include "IRendererFactory.h"

IRendererFactory::IRendererFactory()
{
}

IRenderer* IRendererFactory::createRenderer(std::string key) const throw()
{
    return nullptr;
}
