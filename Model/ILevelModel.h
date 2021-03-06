#ifndef I_LEVEL_MODEL_CLASS_H
#define I_LEVEL_MODEL_CLASS_H

#include <vector>

#include <json/json.h>

#include "BoardObject.h"

class ILevelModel
{
public:
	ILevelModel();
	~ILevelModel();

	virtual bool modifyModel(std::string message);

	virtual bool playerMove(int x, int y);
	virtual void playerStop();
	virtual void playerChange(bool next);
	virtual bool interact();

	void addBoardObject(BoardObject* obj);
	std::vector<BoardObject*>* getBoardObjectsVector();
	std::vector<BoardObject*>::iterator getBoardObjects();
	std::vector<BoardObject*>::iterator getBoardObjectsEnd();

	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();

protected:
	int width;
	int height;
	//TODO THink about instead of a vector,
	//having a tree of composed boardObjects.
	//Might be over kill for what we are making but hey
	std::vector<BoardObject*> boardObjects;
};

#endif