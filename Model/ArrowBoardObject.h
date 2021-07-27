#ifndef ARROW_BOARD_OBJECT_CLASS_H
#define ARROW_BOARD_OBJECT_CLASS_H

#include "BoardObject.h"

class ArrowBoardObject: public BoardObject
{
public:
	ArrowBoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey = "Cutout");

	BoardObject* copy() override;

	bool interact(BoardObject* otherObj, ILevelModel* model) override;
	bool needsInteractReciever() override;

	bool push(BoardObjectAction* pushAction) override;

	bool levitateMe() override;

	bool freeze() override;
	bool melt() override;
	void correctWaterVisual() override;
};

#endif