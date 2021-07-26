#ifndef OBSTACLE_BOARD_OBJECT_CLASS_H
#define OBSTACLE_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class ObstacleBoardObject: public BoardObject
{
public:
	ObstacleBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");

	BoardObject* copy() override;

	bool interact(BoardObject* otherObj, ILevelModel* model) override;

	bool push(BoardObjectAction* pushAction) override;
};

#endif