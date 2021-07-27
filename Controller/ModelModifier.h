#ifndef MODEL_MODIFIER_CLASS_H
#define MODEL_MODIFIER_CLASS_H

#include "IModelModifier.h"

class ModelModifier: public IModelModifier
{
public:
	ModelModifier();

	bool modify(std::string key) override;

};

#endif