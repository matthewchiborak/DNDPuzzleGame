#ifndef RENDERER_FACTORY_CLASS_H
#define RENDERER_FACTORY_CLASS_H

#include "IRendererFactory.h"

class RendererFactory: public IRendererFactory
{
public:
	RendererFactory();

	IRenderer* createRenderer(std::string key) const throw();
};

#endif