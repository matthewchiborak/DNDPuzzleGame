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

	void addTile(BoardObject* tile);
	void addPlayer(BoardObject* player);
	void addObstacle(BoardObject* obs);
	void addWall(BoardObject* wall);
	void addPit(BoardObject* pit);

private:
	int currentPlayerIndex;
	BoardObject* currentPlayer;
	std::vector<BoardObject*> tiles;
	std::vector<BoardObject*> players; //This will only contain PlayerBoardObjects though.... TODO consider
	std::vector<BoardObject*> obstacles;
	std::vector<BoardObject*> walls;
	std::vector<BoardObject*> pits;

	bool isSpaceOccupied(int x, int y, BoardObject** occupyingRef);
	bool doesSpaceExist(int x, int y) override;

};

#endif