#ifndef LEVEL_MODEL_CLASS_H
#define LEVEL_MODEL_CLASS_H

#include "ILevelModel.h"

class LevelModel: public ILevelModel
{
public:
	LevelModel();

	bool playerMove(int x, int y);
	void playerStop() override;
	void rockStop() override;
	void playerChange(bool next) override;
	bool interact() override;
	void handleOverlaps() override;
	void handleOverlapsArrows();
	void handleOverlapsRocks();
	void addArrow(BoardObject* obj) override;

	void addTile(BoardObject* tile);
	void addPlayer(BoardObject* player);
	void addObstacle(BoardObject* obs);
	void addWall(BoardObject* wall);
	void addPit(BoardObject* pit);
	void addWater(BoardObject* water);

	bool isAPit(int x, int y);
	bool isAWater(int x, int y);

	void checkForMelt(int sx, int sy, int ex, int ey);

private:
	int currentPlayerIndex;
	BoardObject* currentPlayer;
	std::vector<BoardObject*> tiles;
	std::vector<BoardObject*> players; //This will only contain PlayerBoardObjects though.... TODO consider
	std::vector<BoardObject*> obstacles;
	std::vector<BoardObject*> walls;
	std::vector<BoardObject*> pits;
	std::vector<BoardObject*> water;
	std::vector<BoardObject*> arrows;

	bool isSpaceOccupied(int x, int y, BoardObject** occupyingRef);
	bool doesSpaceExist(int x, int y) override;

	bool isFrozenWater(int x, int y);

	void correctWaterVisual();

};

#endif