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

	if (key == "Test")
	{
		IModel* model = new Model("models/bunny/scene.gltf");
		flyweights.insert(std::pair<std::string, IModel*>(key, model));
		return model;
	}

	throw (key);
}
