#ifndef I_LEVEL_FACTORY_CLASS_H
#define I_LEVEL_FACTORY_CLASS_H

#include <string>

#include "../Model/ILevelModel.h"

class ILevelFactory
{
public:
	ILevelFactory();

	virtual ILevelModel* createLevel(std::string key) throw();

};

#endif