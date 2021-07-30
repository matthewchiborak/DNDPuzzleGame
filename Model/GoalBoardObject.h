#ifndef GOAL_BOARD_OBJECT_CLASS_H
#define GOAL_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class GoalBoardObject: public BoardObject
{
public:
	GoalBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");
	~GoalBoardObject();

	bool needsInteractReciever() override;
	bool interact(BoardObject* otherObj) override;
};

#endif