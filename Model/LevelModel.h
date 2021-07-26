#ifndef LEVEL_MODEL_CLASS_H
#define LEVEL_MODEL_CLASS_H

#include "ILevelModel.h"

class LevelModel: public ILevelModel
{
public:
	LevelModel();

	bool playerMove(int x, int y);
	void playerStop();
	void playerChange(bool next);
	bool interact() override;

	void addPlayer(BoardObject* player);
	void addObstacle(BoardObject* obs);

private:
	int currentPlayerIndex;
	BoardObject* currentPlayer;
	std::vector<BoardObject*> players; //This will only contain PlayerBoardObjects though.... TODO consider
	std::vector<BoardObject*> obstacles;

	bool isSpaceOccupied(int x, int y, BoardObject** occupyingRef);

};

#endif