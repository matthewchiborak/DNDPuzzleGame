#ifndef LEVEL_MODEL_CLASS_H
#define LEVEL_MODEL_CLASS_H

#include "ILevelModel.h"



#include "../Model/ArrowBoardObject.h"
#include "../Model/ObstacleBoardObject.h"
#include "../Model/PitBoardObject.h"
#include "../Model/PlayerBoardObject.h"
#include "../Model/TileBoardObject.h"
#include "../Model/WallBoardObject.h"
#include "../Model/WaterBoardObject.h"

class IModelModifier;

class LevelModel: public ILevelModel
{
public:
	LevelModel(IModelModifier* modifier);
	~LevelModel();

	bool modifyModel(std::string message) override;

	bool playerMove(int x, int y);
	void playerStop() override;
	void playerChange(bool next) override;
	bool interact() override;

	void addArrow(ArrowBoardObject* obj);
	void addTile(TileBoardObject* tile);
	void addPlayer(PlayerBoardObject* player);
	void addObstacle(ObstacleBoardObject* obs);
	void addWall(WallBoardObject* wall);
	void addPit(PitBoardObject* pit);
	void addWater(WaterBoardObject* water);

	std::vector<TileBoardObject*>* getTiles();
	std::vector<PlayerBoardObject*>* getPlayers();
	std::vector<ObstacleBoardObject*>* getObstacles();
	std::vector<WallBoardObject*>* getWalls();
	std::vector<PitBoardObject*>* getPits();
	std::vector<WaterBoardObject*>* getWater();
	std::vector<ArrowBoardObject*>* getArrows();

private:
	IModelModifier* modelModifier;
	int currentPlayerIndex;
	PlayerBoardObject* currentPlayer;
	std::vector<TileBoardObject*> tiles;
	std::vector<PlayerBoardObject*> players;
	std::vector<ObstacleBoardObject*> obstacles;
	std::vector<WallBoardObject*> walls;
	std::vector<PitBoardObject*> pits;
	std::vector<WaterBoardObject*> water;
	std::vector<ArrowBoardObject*> arrows;

	bool isSpaceOccupied(int x, int y, BoardObject** occupyingRef);
};

#endif