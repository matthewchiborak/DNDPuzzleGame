#include "IGameStateFactory.h"

IGameStateFactory::IGameStateFactory()
{
}

IGameState* IGameStateFactory::createState(std::string key, IGameController* controller, ILevelModel* level) throw()
{
    return nullptr;
}
