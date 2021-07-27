#ifndef INTERACT_COMMAND_ROCK_FLOAT_CLASS_H
#define INTERACT_COMMAND_ROCK_FLOAT_CLASS_H

#include "InteractCommand.h"

#include "../Model/ObstacleBoardObject.h"

class InteractCommandRockFloat: public InteractCommand
{
public:
	InteractCommandRockFloat(LevelModel* model);

	void setReciever(ObstacleBoardObject* reciever);

	bool execute(BoardObject* initer, BoardObject* otherObj) override;

	bool needsReciever() override;

private:
	ObstacleBoardObject* reciever;
};

#endif