#ifndef INTERACT_COMMAND_ROCK_FLOAT_CLASS_H
#define INTERACT_COMMAND_ROCK_FLOAT_CLASS_H

#include "InteractCommand.h"

class InteractCommandRockFloat: public InteractCommand
{
public:
	InteractCommandRockFloat();

	bool execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model) override;

};

#endif