#ifndef MODEL_FLYWEIGHT_FACTORY_CLASS_H
#define MODEL_FLYWEIGHT_FACTORY_CLASS_H

#include "IModelFlyweightFactory.h"

class ModelFlyweightFactory: public IModelFlyweightFactory
{
public:
	ModelFlyweightFactory();

	Model* getFlyweight(std::string key) throw() override;

protected:
	Model* createFlyweight(std::string key) throw();
};

#endif