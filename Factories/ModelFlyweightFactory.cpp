#include "ModelFlyweightFactory.h"

#include "../Rendering/Core/Model.h"
#include "../Rendering/ModelPlane.h"

ModelFlyweightFactory::ModelFlyweightFactory()
	: IModelFlyweightFactory()
{
}

IModel* ModelFlyweightFactory::getFlyweight(std::string key) throw()
{
	if (flyweights.find(key) == flyweights.end())
	{
		return createFlyweight(key);
	}

	return flyweights.at(key);
}

IModel* ModelFlyweightFactory::createFlyweight(std::string key) throw()
{
	if (key == "Test")
	{
		IModel* model = new Model("models/bunny/scene.gltf");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Tile")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Tile.png");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Duke")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Duke.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Bullent")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Bullent.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Chad")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Chad.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Rock")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Rock.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Grass")
	{
		IModel* model = new Model("models/grass/scene.gltf");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}

	throw (key);
}
