#ifndef PLAYER_BOARD_OBJECT_CLASS_H
#define PLAYER_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

#include "../InteractCommands/InteractCommand.h"

class PlayerBoardObject: public BoardObject
{
public:
	PlayerBoardObject(int posX, int posY, int height, InteractCommand* iCommand, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");
	~PlayerBoardObject();

	bool interact(BoardObject* otherObj, ILevelModel* model) override;
	bool push(BoardObjectAction* pushAction) override;

	BoardObject* copy() override;

private:
	InteractCommand* interactCommand;
};

#endif