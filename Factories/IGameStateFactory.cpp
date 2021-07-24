#include "IGameStateFactory.h"

IGameStateFactory::IGameStateFactory()
{
}

IGameState* IGameStateFactory::createState(std::string key, IGameController* controller, ILevelModel* level) const throw()
{
    return nullptr;
}
