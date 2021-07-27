#ifndef INTERACT_COMMAND_ROCK_PUSH_CLASS_H
#define INTERACT_COMMAND_ROCK_PUSH_CLASS_H

#include "InteractCommand.h"

class InteractCommandRockPush: public InteractCommand
{
public:
	InteractCommandRockPush();

	bool execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model) override;
	
private:
	bool isAPitOrWater(ILevelModel* model, int x, int y);
};

#endif