#ifndef MODEL_FLYWEIGHT_FACTORY_CLASS_H
#define MODEL_FLYWEIGHT_FACTORY_CLASS_H

#include "IModelFlyweightFactory.h"

class ModelFlyweightFactory: public IModelFlyweightFactory
{
public:
	ModelFlyweightFactory();

	IModel* getFlyweight(std::string key) throw() override;

protected:
	IModel* createFlyweight(std::string key) throw();
};

#endif