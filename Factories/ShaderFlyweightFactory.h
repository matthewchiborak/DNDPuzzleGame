#ifndef SHADER_FLYWEIGHT_FACTORY_CLASS_H
#define SHADER_FLYWEIGHT_FACTORY_CLASS_H

#include "IShaderFlyweightFactory.h"

class ShaderFlyweightFactory: public IShaderFlyweightFactory
{
public:
	ShaderFlyweightFactory();

	Shader* getFlyweight(std::string key) throw() override;

protected:
	Shader* createFlyweight(std::string key) throw();
	void activateShader(Shader* shader, bool isLight);
};

#endif