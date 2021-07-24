#ifndef I_RENDERER_FACTORY_CLASS_H
#define I_RENDERER_FACTORY_CLASS_H

#include <string>

#include "../Rendering/IRenderer.h"

//Will have to decide if want window created here. Or created higher up and passed in. I think it woudl be cleaner here. Ill sleep on it

class IRendererFactory
{
public:
	IRendererFactory();

	virtual IRenderer* createRenderer(std::string key) const throw();
};

#endif