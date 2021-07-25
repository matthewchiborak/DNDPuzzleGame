#ifndef MODEL_PLANE_CLASS_H
#define MODEL_PLANE_CLASS_H

#include "IModel.h"

using json = nlohmann::json;


class ModelPlane: public IModel
{
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	ModelPlane();
	ModelPlane(float width, float height, std::string textureFilePath);

	void Draw(
		Shader& shader,
		Camera& camera,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	) override;

private:
	float width;
	float height;
	Mesh mesh1;
	Mesh mesh2;
	std::vector<Texture> loadedTex;
};
#endif