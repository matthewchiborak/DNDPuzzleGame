#ifndef I_SHADER_FLYWEIGHT_FACTORY_CLASS_H
#define I_SHADER_FLYWEIGHT_FACTORY_CLASS_H

#include <string>
#include <map>

#include "../Rendering/Core/shader.h"
#include "../Rendering/Core/ShaderSkybox.h"

class IShaderFlyweightFactory
{
public:
	IShaderFlyweightFactory();
	~IShaderFlyweightFactory();

	virtual Shader* getFlyweight(std::string key) throw();

protected:
	std::map<std::string, Shader*> flyweights;
};

#endif