#include "LevelFactory.h"

#include <json/json.h>

#include <fstream>
#include <streambuf>

#include "../Model/LevelModel.h"
#include "../Model/PlayerBoardObject.h"
#include "../Model/TileBoardObject.h"
#include "../Model/ObstacleBoardObject.h"
#include "../Model/WallBoardObject.h"
#include "../Model/PitBoardObject.h"
#include "../Model/WaterBoardObject.h"

#include "../BoardObjectActions/BoardObjectActionNone.h"

#include "../InteractCommands/InteractCommandNone.h"
#include "../InteractCommands/InteractCommandRockPush.h"
#include "../InteractCommands/InteractCommandRockFloat.h"
#include "../InteractCommands/InteractCommandFreeze.h"

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

		//Tiles
		newLevel->setWidth(JSON["Width"]);
		newLevel->setHeight(JSON["Height"]);
		for (int i = 0; i < newLevel->getWidth(); i++)
		{
			for (int j = 0; j < newLevel->getHeight(); j++)
			{
				bool okayToAdd = true;
				for (int k = 0; k < JSON["NoTiles"].size(); k++)
				{
					if (JSON["NoTiles"][k]["PosX"] == i && JSON["NoTiles"][k]["PosY"] == j)
						okayToAdd = false;
				}
				if(okayToAdd)
					newLevel->addTile(new TileBoardObject(i, j, 0, new BoardObjectActionNone(), "Tile"));
			}
		}

		//Walls
		for (int i = 0; i < JSON["Walls"].size(); i++)
		{
			newLevel->addWall(new WallBoardObject(JSON["Walls"][i]["PosX"], JSON["Walls"][i]["PosY"], 1, new BoardObjectActionNone(), JSON["Walls"][i]["Model"]));
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
			newLevel->addObstacle(new ObstacleBoardObject(JSON["Rocks"][i]["PosX"], JSON["Rocks"][i]["PosY"], 1, new BoardObjectActionNone(), JSON["Rocks"][i]["Model"]));
		}

		//Pits
		for (int i = 0; i < JSON["Pits"].size(); i++)
		{
			newLevel->addPit(new PitBoardObject(JSON["Pits"][i]["PosX"], JSON["Pits"][i]["PosY"], 0, new BoardObjectActionNone(), JSON["Pits"][i]["Model"]));
		}
		
		//Water
		for (int i = 0; i < JSON["Water"].size(); i++)
		{
			newLevel->addWater(new WaterBoardObject(JSON["Water"][i]["PosX"], JSON["Water"][i]["PosY"], 0, new BoardObjectActionNone(), JSON["Water"][i]["Model"], JSON["Water"][i]["ModelFreeze"]));
		}

		return newLevel;
	}

	throw(key);
}

InteractCommand* LevelFactory::createInteractCommand(std::string key)
{
	if (key == "RockPush")
		return new InteractCommandRockPush();

	if (key == "RockFloat")
		return new InteractCommandRockFloat();

	if (key == "Freeze")
		return new InteractCommandFreeze();

	return new InteractCommandNone();
}
