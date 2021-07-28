#include "ModelFlyweightFactory.h"

#include "../Rendering/Core/Model.h"
#include "../Rendering/ModelPlane.h"
#include "../Rendering/ModelCube.h"
#include "../Rendering/ModelPit.h"

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
	std::ifstream t("Textures/ModelPaths.json");
	std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	nlohmann::json JSON = nlohmann::json::parse(text);

	if (JSON[key]["Type"] == "Plane")
	{
		IModel* model = new ModelPlane(1, 1, JSON[key]["Path"], JSON[key]["IsVert"]);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (JSON[key]["Type"] == "Cube")
	{
		IModel* model = new ModelCube(1, 1, JSON[key]["Path"]);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (JSON[key]["Type"] == "Pit")
	{
		IModel* model = new ModelPit(1, 1, JSON[key]["Path"]);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}

	///
	/*
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
	else if (key == "Wall")
	{
		IModel* model = new ModelCube(1, 1, "Textures/Wall.png");
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
	else if (key == "Allura")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Allura.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Rock")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Rock.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Pit")
	{
		IModel* model = new ModelPit(1, 1, "Textures/Wall.png");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Water")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Water.png");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Ice")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Ice.png");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Arrow")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Arrow.png");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Skeleton")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Skeleton.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}
	else if (key == "Goblin")
	{
		IModel* model = new ModelPlane(1, 1, "Textures/Goblin.png", true);
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}*/

	throw (key);
}
