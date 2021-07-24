#include "LevelFactory.h"

#include "../Model/LevelModel.h"

LevelFactory::LevelFactory()
	: ILevelFactory()
{

}

ILevelModel* LevelFactory::createLevel(int levelNo) const throw()
{
	if(levelNo == 1)
		return new LevelModel();

	throw(levelNo);
}
