#ifndef INTERACT_COMMAND_SHOOT_CLASS_H
#define INTERACT_COMMAND_SHOOT_CLASS_H

#include <json/json.h>

#include "InteractCommand.h"

class InteractCommandShoot: public InteractCommand
{
public:
	InteractCommandShoot(std::string arrowModelKey, LevelModel* model);

	bool execute(BoardObject* initer, BoardObject* otherObj) override;

	bool needsReciever() override;

private:
	std::string arrowModelKey;
	BoardObject* initer;

	bool isAPitOrWater(ILevelModel* model, int x, int y);

	void findClosestValue(int xDir, int yDir, int objectX, int objectY, int distanceOffset, bool* closestSet, int* closestValue);
	bool findClosestValueNotExist(int xDir, int yDir, bool* closestSet, int* closestValue);

	std::string buildSpaceExistMessage(int x, int y);
};

#endif