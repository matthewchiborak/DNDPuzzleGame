#include "RendererFactory.h"

#include "../Rendering/BoardRenderer.h"

RendererFactory::RendererFactory()
	: IRendererFactory()
{
}

IRenderer* RendererFactory::createRenderer(std::string key) const throw()
{
	if (key == "Board")
		return new BoardRenderer();

	throw(key);
}
