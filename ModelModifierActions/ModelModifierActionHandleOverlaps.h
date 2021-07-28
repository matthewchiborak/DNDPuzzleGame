#ifndef MODEL_MODIFIER_ACTION_HANDLE_OVERLAPS_CLASS_H
#define MODEL_MODIFIER_ACTION_HANDLE_OVERLAPS_CLASS_H

#include "ModelModifierAction.h"

class ModelModifierActionHandleOverlaps: public ModelModifierAction
{
public:
	ModelModifierActionHandleOverlaps(LevelModel* level);

	bool execute(nlohmann::json* message) override;

private:
	void handleOverlapsArrows();
	void handleOverlapsRocks();
};

#endif