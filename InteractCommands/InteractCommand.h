#ifndef INTERACT_COMMAND_CLASS_H
#define INTERACT_COMMAND_CLASS_H

#include "../Model/BoardObject.h"
#include "../Model/ILevelModel.h"

class InteractCommand
{
public:
	InteractCommand();

	virtual bool needsReciever();

	virtual bool execute(BoardObject* initer, BoardObject* reciever, ILevelModel* model);

};

#endif