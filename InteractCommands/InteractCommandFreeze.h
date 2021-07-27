#ifndef INTERACT_COMMAND_FREEZE_CLASS_H
#define INTERACT_COMMAND_FREEZE_CLASS_H

#include "InteractCommand.h"

class InteractCommandFreeze: public InteractCommand
{
public:
	InteractCommandFreeze();

	bool execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model) override;

	bool needsReciever() override;

};

#endif