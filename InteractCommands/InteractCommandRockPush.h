#ifndef INTERACT_COMMAND_ROCK_PUSH_CLASS_H
#define INTERACT_COMMAND_ROCK_PUSH_CLASS_H

#include <json/json.h>

#include "InteractCommand.h"

#include "../Model/ObstacleBoardObject.h"

class InteractCommandRockPush: public InteractCommand
{
public:
	InteractCommandRockPush(LevelModel* model);

	void setReciever(ObstacleBoardObject* reciever);

	bool execute(BoardObject* initer, BoardObject* otherObj) override;

	bool needsReciever() override;
	
private:
	bool isAPitOrWater(ILevelModel* model, int x, int y);

	ObstacleBoardObject* reciever;

	bool executeForReceiverIsFloating(BoardObject* initer);
	bool executeForReceiverIsOnTheGround(BoardObject* initer);

	void findClosestValue(int xDir, int yDir, int objectX, int objectY, int distanceOffset, bool* closestSet, int* closestValue);
	bool findClosestValueNotExist(int xDir, int yDir, bool* closestSet, int* closestValue);

	std::string buildSpaceExistMessage(int x, int y);
};

#endif