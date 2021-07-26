#include "LevelFactory.h"

#include <json/json.h>

#include <fstream>
#include <streambuf>

#include "../Model/LevelModel.h"
#include "../Model/PlayerBoardObject.h"
#include "../Model/TileBoardObject.h"

#include "../BoardObjectActions/BoardObjectActionNone.h"

#include "../InteractCommands/InteractCommandNone.h"
#include "../InteractCommands/InteractCommandRockPush.h"

LevelFactory::LevelFactory()
	: ILevelFactory()
{

}

ILevelModel* LevelFactory::createLevel(std::string key) throw()
{
	if (key == "-1") //Empty model
		return new LevelModel();
	else
	{
		// Make a JSON object
		std::ifstream t("Levels/" + key + ".json");
		std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
		nlohmann::json JSON = nlohmann::json::parse(text);

		//Create the level
		LevelModel* newLevel = new LevelModel();

		//Titles
		newLevel->setWidth(JSON["Width"]);
		newLevel->setHeight(JSON["Height"]);
		for (int i = 0; i < newLevel->getWidth(); i++)
		{
			for (int j = 0; j < newLevel->getHeight(); j++)
			{
				newLevel->addBoardObject(new TileBoardObject(i, j, 0, new BoardObjectActionNone(), "Tile"));
			}
		}

		//Players
		for (int i = 0; i < JSON["Players"].size(); i++)
		{
			newLevel->addPlayer(new PlayerBoardObject(
				JSON["Players"][i]["PosX"], 
				JSON["Players"][i]["PosY"],
				1, 
				createInteractCommand(JSON["Players"][i]["Interact"]),
				new BoardObjectActionNone(), 
				JSON["Players"][i]["Model"]));
		}

		//Rocks
		for (int i = 0; i < JSON["Rocks"].size(); i++)
		{
			newLevel->addPlayer(new PlayerBoardObject(JSON["Rocks"][i]["PosX"], JSON["Rocks"][i]["PosY"], 1, createInteractCommand("None"), new BoardObjectActionNone(), JSON["Rocks"][i]["Model"]));
		}
		
		return newLevel;
	}

	throw(key);
}

InteractCommand* LevelFactory::createInteractCommand(std::string key)
{
	if (key == "RockPush")
		return new InteractCommandRockPush();
	
	return new InteractCommandNone();
}
