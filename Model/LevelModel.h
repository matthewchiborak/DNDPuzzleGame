#ifndef LEVEL_MODEL_CLASS_H
#define LEVEL_MODEL_CLASS_H

#include "ILevelModel.h"

class LevelModel: public ILevelModel
{
public:
	LevelModel();

	bool playerMove(int x, int y);
	void playerStop();
	void rockStop();
	void playerChange(bool next);
	bool interact() override;

	void addTile(BoardObject* tile);
	void addPlayer(BoardObject* player);
	void addObstacle(BoardObject* obs);
	void addWall(BoardObject* wall);

private:
	int currentPlayerIndex;
	BoardObject* currentPlayer;
	std::vector<BoardObject*> tiles;
	std::vector<BoardObject*> players; //This will only contain PlayerBoardObjects though.... TODO consider
	std::vector<BoardObject*> obstacles;
	std::vector<BoardObject*> walls;

	bool isSpaceOccupied(int x, int y, BoardObject** occupyingRef);
	bool doesSpaceExist(int x, int y) override;

};

#endif