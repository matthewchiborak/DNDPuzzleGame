#include "GameStateFactory.h"

#include "../Controller/GameStateMove.h"
#include "../Controller/GameStateStop.h"

GameStateFactory::GameStateFactory()
	: IGameStateFactory()
{
}

IGameState* GameStateFactory::createState(std::string key, IGameController* controller, ILevelModel* level) const throw()
{
	if (key == "Stop")
		return new GameStateStop(controller, level);
	if (key == "Move")
		return new GameStateMove(controller, level);

	throw(key);
}
