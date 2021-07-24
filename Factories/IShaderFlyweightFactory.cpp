#include "IShaderFlyweightFactory.h"

IShaderFlyweightFactory::IShaderFlyweightFactory()
{
}

IShaderFlyweightFactory::~IShaderFlyweightFactory()
{
    std::map<std::string, Shader*>::iterator it;

    for (it = flyweights.begin(); it != flyweights.end(); it++)
    {
        it->second->Delete();
        delete it->second;
    }
}

Shader* IShaderFlyweightFactory::getFlyweight(std::string key) throw()
{
	return nullptr;
}
