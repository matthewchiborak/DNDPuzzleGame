#include "ModelFlyweightFactory.h"

ModelFlyweightFactory::ModelFlyweightFactory()
	: IModelFlyweightFactory()
{
}

Model* ModelFlyweightFactory::getFlyweight(std::string key) throw()
{
	if (flyweights.find(key) == flyweights.end())
	{
		return createFlyweight(key);
	}

	return flyweights.at(key);
}

Model* ModelFlyweightFactory::createFlyweight(std::string key) throw()
{
	if (key == "Test")
	{
		Model* model = new Model("models/bunny/scene.gltf");
		flyweights.insert(std::pair<std::string, Model*>(key, model));
		return model;
	}
	else if (key == "Grass")
	{
		Model* model = new Model("models/grass/scene.gltf");
		flyweights.insert(std::pair<std::string, Model*>(key, model));
		return model;
	}

	throw (key);
}
