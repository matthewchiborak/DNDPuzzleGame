#ifndef BOARD_OBJECT_CLASS_H
#define BOARD_OBJECT_CLASS_H

#include <string>

class BoardObjectAction;
class ILevelModel;

class BoardObject
{
public:
	BoardObject(int posX, int posY, int height, bool solid, BoardObjectAction* action, std::string modelKey, std::string shaderKey);

	void setCurrentAction(BoardObjectAction* action);
	void doBoardObjectAction(float t);

	void move(int x, int y);
	virtual bool interact(BoardObject* otherObj, ILevelModel* model);

	void setPos(int x, int y);
	void setVis(float x, float y);
	void setLastDirMoved(int x, int y);

	int getPosX(); 
	int getPosY();
	float getVisX();
	float getVisY();
	int getHeight();
	int getLastDirMovedX();
	int getLastDirMovedY();
	std::string getModelKey();
	std::string getShaderKey();

	bool isSolid();

protected:
	int posX, posY, height; //Position in the game grid
	bool solid;
	float visX, visY; //Position in the game world for drawing
	std::string modelKey;
	std::string shaderKey;

	int lastDirMovedx;
	int lastDirMovedy;

	BoardObjectAction* currentAction;
	//TODO interact command
};

#endif