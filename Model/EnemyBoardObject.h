#ifndef ENEMY_BOARD_OBJECT_CLASS_H
#define ENEMY_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class EnemyBoardObject: public BoardObject
{
public:
	EnemyBoardObject(int posX, int posY, int height, bool squishy, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");
	~EnemyBoardObject();

	bool needsInteractReciever() override;
	bool interact(BoardObject* otherObj) override;

	int getNextXPos();
	int getNextYPos();
};

#endif