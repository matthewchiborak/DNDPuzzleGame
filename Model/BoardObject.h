#ifndef BOARD_OBJECT_CLASS_H
#define BOARD_OBJECT_CLASS_H

#include <string>

class BoardObjectAction;

class BoardObject
{
public:
	BoardObject(int posX, int posY, int height, BoardObjectAction* action, std::string modelKey, std::string shaderKey);

	void setCurrentAction(BoardObjectAction* action);
	void doBoardObjectAction(float t);

	void move(int x, int y);
	virtual void interact(BoardObject* otherObj);

	void setPos(int x, int y);
	void setVis(float x, float y);

	int getPosX(); 
	int getPosY();
	float getVisX();
	float getVisY();
	int getHeight();
	std::string getModelKey();
	std::string getShaderKey();

protected:
	int posX, posY, height; //Position in the game grid
	float visX, visY; //Position in the game world for drawing
	std::string modelKey;
	std::string shaderKey;

	BoardObjectAction* currentAction;
	//TODO interact command
};

#endif