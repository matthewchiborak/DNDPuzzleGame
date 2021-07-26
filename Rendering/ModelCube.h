#ifndef MODEL_CUBE_CLASS_H
#define MODEL_CUBE_CLASS_H

#include "IModel.h"

using json = nlohmann::json;


class ModelCube: public IModel
{
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	ModelCube();
	ModelCube(float width, float height, std::string textureFilePath);

	void Draw(
		Shader& shader,
		Camera& camera,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	) override;

private:
	void makeTop(std::string textureFilePath);
	void makeFront(std::string textureFilePath);
	
	void makeRight(std::string textureFilePath);
	void makeLeft(std::string textureFilePath);

	float elevationOffset;

	float width;
	float height;
	Mesh meshTop1;
	Mesh meshTop2;
	Mesh meshFront1;
	Mesh meshFront2;
	Mesh meshRight1;
	Mesh meshRight2;
	Mesh meshLeft1;
	Mesh meshLeft2;
	std::vector<Texture> loadedTex;
};
#endif