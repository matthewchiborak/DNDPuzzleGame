#ifndef I_MODEL_FLYWEIGHT_FACTORY_CLASS_H
#define I_MODEL_FLYWEIGHT_FACTORY_CLASS_H

#include <string>
#include <map>

#include "../Rendering/Core/Model.h"


class IModelFlyweightFactory
{
public:
	IModelFlyweightFactory();

	virtual Model* getFlyweight(std::string key) throw();

protected:
	std::map<std::string, Model*> flyweights;
};

#endif