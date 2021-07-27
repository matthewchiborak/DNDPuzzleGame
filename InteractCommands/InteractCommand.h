#ifndef INTERACT_COMMAND_CLASS_H
#define INTERACT_COMMAND_CLASS_H

#include "../Model/BoardObject.h"

class LevelModel;

class InteractCommand
{
public:
	InteractCommand(LevelModel* model);

	virtual bool needsReciever();

	virtual bool execute(BoardObject* initer, BoardObject* otherObj);

protected:
	LevelModel* model;
};

#endif