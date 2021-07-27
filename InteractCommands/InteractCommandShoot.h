#ifndef INTERACT_COMMAND_SHOOT_CLASS_H
#define INTERACT_COMMAND_SHOOT_CLASS_H

#include "InteractCommand.h"

class InteractCommandShoot: public InteractCommand
{
public:
	InteractCommandShoot(std::string arrowModelKey);

	bool execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model) override;

	bool needsReciever() override;

private:
	std::string arrowModelKey;

	bool isAPitOrWater(ILevelModel* model, int x, int y);
};

#endif