#ifndef I_SKYBOX_FLYWEIGHT_FACTORY_CLASS_H
#define I_SKYBOX_FLYWEIGHT_FACTORY_CLASS_H

#include <string>
#include <map>

#include "../Rendering/Skybox.h"


class ISkyboxFlyweightFactory
{
public:
	ISkyboxFlyweightFactory();

	virtual Skybox* getFlyweight(std::string key) throw();

protected:
	std::map<std::string, Skybox*> flyweights;
};

#endif