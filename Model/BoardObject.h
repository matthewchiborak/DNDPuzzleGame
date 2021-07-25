#ifndef BOARD_OBJECT_CLASS_H
#define BOARD_OBJECT_CLASS_H

#include <string>

class BoardObject
{
public:
	BoardObject(int posX, int posY, int height, std::string modelKey, std::string shaderKey);

	void move(int x, int y);
	virtual void interact(BoardObject* otherObj);

	int getPosX(); 
	int getPosY();
	int getHeight();
	std::string getModelKey();
	std::string getShaderKey();

protected:
	int posX, posY, height; //Position in the game grid
	std::string modelKey;
	std::string shaderKey;
	//TODO interact command
};

#endif