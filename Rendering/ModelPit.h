#ifndef MODEL_PIT_CLASS_H
#define MODEL_PIT_CLASS_H

#include "IModel.h"

using json = nlohmann::json;


class ModelPit: public IModel
{
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	ModelPit();
	ModelPit(float width, float height, std::string textureFilePath);

	void Draw(
		Shader& shader,
		Camera& camera,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	) override;

private:
	void makeBottom(std::string textureFilePath);
	void makeBack(std::string textureFilePath);
	
	void makeRight(std::string textureFilePath);
	void makeLeft(std::string textureFilePath);

	float elevationOffset;

	float width;
	float height;
	Mesh meshBot1;
	Mesh meshBot2;
	Mesh meshBack1;
	Mesh meshBack2;
	Mesh meshRight1;
	Mesh meshRight2;
	Mesh meshLeft1;
	Mesh meshLeft2;
	std::vector<Texture> loadedTex;
};
#endif