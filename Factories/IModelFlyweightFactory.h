#ifndef I_MODEL_FLYWEIGHT_FACTORY_CLASS_H
#define I_MODEL_FLYWEIGHT_FACTORY_CLASS_H

#include <string>
#include <map>

#include "../Rendering/IModel.h"


class IModelFlyweightFactory
{
public:
	IModelFlyweightFactory();

	virtual IModel* getFlyweight(std::string key) throw();

protected:
	std::map<std::string, IModel*> flyweights;
};

#endif