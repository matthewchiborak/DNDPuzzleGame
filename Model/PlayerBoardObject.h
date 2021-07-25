#ifndef PLAYER_BOARD_OBJECT_CLASS_H
#define PLAYER_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class PlayerBoardObject: public BoardObject
{
public:
	PlayerBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Default");

	void interact(BoardObject* otherObj) override;

};

#endif