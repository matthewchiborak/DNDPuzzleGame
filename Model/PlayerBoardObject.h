#ifndef PLAYER_BOARD_OBJECT_CLASS_H
#define PLAYER_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

#include "../InteractCommands/InteractCommand.h"

class PlayerBoardObject: public BoardObject
{
public:
	PlayerBoardObject(int posX, int posY, int height, InteractCommand* iCommand, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");
	~PlayerBoardObject();

	bool needsInteractReciever() override;
	InteractCommand* getInteractCommand();
	bool interact(BoardObject* otherObj) override;

private:
	InteractCommand* interactCommand;
};

#endif