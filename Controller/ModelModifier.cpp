#include "ModelModifier.h"

#include <iostream>

#include "../BoardObjectActions/BoardObjectActionNone.h"

#include "../ModelModifierActions/ModelModifierActionRockStop.h"
#include "../ModelModifierActions/ModelModifierActionSpaceExist.h"
#include "../ModelModifierActions/ModelModifierActionIsPit.h"
#include "../ModelModifierActions/ModelModifierActionIsWater.h"
#include "../ModelModifierActions/ModelModifierActionCheckMelt.h"
#include "../ModelModifierActions/ModelModifierActionHandleOverlaps.h"
#include "../ModelModifierActions/ModelModifierActionCorrectWater.h"

ModelModifier::ModelModifier()
	: IModelModifier()
{
}

bool ModelModifier::modify(std::string message)
{
	nlohmann::json JSON = nlohmann::json::parse(message);

	if (JSON["Key"] == "RockStop")
	{
		ModelModifierActionRockStop mma(this->level);
		return mma.execute(&JSON);
	}

	if (JSON["Key"] == "SpaceExist")
	{
		ModelModifierActionSpaceExist mma(this->level);
		return mma.execute(&JSON);
	}

	if (JSON["Key"] == "IsPit")
	{
		ModelModifierActionIsPit mma(this->level);
		return mma.execute(&JSON);
	}

	if (JSON["Key"] == "IsWater")
	{
		ModelModifierActionIsWater mma(this->level);
		return mma.execute(&JSON);
	}

	if (JSON["Key"] == "CheckMelt")
	{
		ModelModifierActionCheckMelt mma(this->level);
		return mma.execute(&JSON);
	}

	if (JSON["Key"] == "HandleOverlaps")
	{
		ModelModifierActionHandleOverlaps mma(this->level);
		return mma.execute(&JSON);
	}

	if (JSON["Key"] == "CorrectWater")
	{
		ModelModifierActionCorrectWater mma(this->level);
		return mma.execute(&JSON);
	}

	return false;
}
