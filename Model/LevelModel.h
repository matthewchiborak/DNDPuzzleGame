#ifndef LEVEL_MODEL_CLASS_H
#define LEVEL_MODEL_CLASS_H

#include "ILevelModel.h"

class LevelModel: public ILevelModel
{
public:
	LevelModel();

	void playerMove(int x, int y);
	void playerStop();
	void interact() override;

	void addPlayer(BoardObject* player);

private:
	BoardObject* currentPlayer;
	std::vector<BoardObject*> players; //This will only contain PlayerBoardObjects though.... TODO consider
};

#endif