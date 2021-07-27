#ifndef INTERACT_COMMAND_FREEZE_CLASS_H
#define INTERACT_COMMAND_FREEZE_CLASS_H

#include "InteractCommand.h"

#include "../Model/WaterBoardObject.h"

class InteractCommandFreeze: public InteractCommand
{
public:
	InteractCommandFreeze(LevelModel* model);

	void setReciever(WaterBoardObject* reciever);

	bool execute(BoardObject* initer, BoardObject* otherObj) override;

	bool needsReciever() override;

private:
	WaterBoardObject* reciever;
};

#endif