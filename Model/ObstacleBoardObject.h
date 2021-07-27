#ifndef OBSTACLE_BOARD_OBJECT_CLASS_H
#define OBSTACLE_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class ObstacleBoardObject: public BoardObject
{
public:
	ObstacleBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");

	bool interact(BoardObject* otherObj) override;
	bool needsInteractReciever() override;

	bool push(BoardObjectAction* pushAction);

	bool levitateMe();
	bool isLevitating();
	void stopLevitate();

private:
	bool leviting;
};

#endif