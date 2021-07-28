#include "ModelModifierActionCheckMelt.h"

ModelModifierActionCheckMelt::ModelModifierActionCheckMelt(LevelModel* level)
	: ModelModifierAction(level)
{
}

bool ModelModifierActionCheckMelt::execute(nlohmann::json* message)
{
	for (int i = 0; i < this->level->getWater()->size(); i++)
	{
		if (!this->level->getWater()->at(i)->isSolid())
		{
			if ((*message)["sx"] == (*message)["ex"] && (*message)["sx"] == this->level->getWater()->at(i)->getPosX())
			{
				if ((this->level->getWater()->at(i)->getPosY() >= (*message)["sy"] && this->level->getWater()->at(i)->getPosY() < (*message)["ey"]) || (this->level->getWater()->at(i)->getPosY() <= (*message)["sy"] && this->level->getWater()->at(i)->getPosY() > (*message)["ey"]))
				{
					this->level->getWater()->at(i)->melt();
				}
			}
			else if ((*message)["sy"] == (*message)["ey"] && (*message)["sy"] == this->level->getWater()->at(i)->getPosY())
			{
				if ((this->level->getWater()->at(i)->getPosX() >= (*message)["sx"] && this->level->getWater()->at(i)->getPosX() < (*message)["ex"]) || (this->level->getWater()->at(i)->getPosX() <= (*message)["sx"] && this->level->getWater()->at(i)->getPosX() > (*message)["ex"]))
				{
					this->level->getWater()->at(i)->melt();
				}
			}
		}
	}

	return true;
}
