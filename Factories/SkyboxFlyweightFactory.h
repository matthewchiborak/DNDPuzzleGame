#ifndef SKYBOX_FLYWEIGHT_FACTORY_CLASS_H
#define SKYBOX_FLYWEIGHT_FACTORY_CLASS_H

#include "ISkyboxFlyweightFactory.h"

class SkyboxFlyweightFactory: public ISkyboxFlyweightFactory
{
public:
	SkyboxFlyweightFactory();

	Skybox* getFlyweight(std::string key) throw() override;

protected:
	Skybox* createFlyweight(std::string key) throw();
};

#endif