#ifndef INTERACT_COMMAND_NONE_CLASS_H
#define INTERACT_COMMAND_NONE_CLASS_H

#include "InteractCommand.h"

class InteractCommandNone: public InteractCommand
{
public:
	InteractCommandNone();

	bool execute(BoardObject* initer, BoardObject* otherObj) override;

	bool needsReciever() override;

};

#endif