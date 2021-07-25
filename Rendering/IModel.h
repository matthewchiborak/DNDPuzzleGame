#ifndef I_MODEL_CLASS_H
#define I_MODEL_CLASS_H

#include <json/json.h>
#include "Core/Mesh.h"

using json = nlohmann::json;


class IModel
{
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	IModel();
	IModel(const char* file, unsigned int instancing = 1, std::vector<glm::mat4> instanceMatrix = {});

	virtual void Draw
	(
		Shader& shader,
		Camera& camera,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

protected:
	// Helps with the assembly from above by grouping floats
	std::vector<glm::vec2> groupFloatsVec2(std::vector<float> floatVec);
	std::vector<glm::vec3> groupFloatsVec3(std::vector<float> floatVec);
	std::vector<glm::vec4> groupFloatsVec4(std::vector<float> floatVec);

	// Assembles all the floats into vertices
	std::vector<Vertex> assembleVertices
	(
		std::vector<glm::vec3> positions,
		std::vector<glm::vec3> normals,
		std::vector<glm::vec2> texUVs
	);
};
#endif