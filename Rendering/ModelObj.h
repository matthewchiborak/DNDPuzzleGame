#ifndef MODEL_OBJ_CLASS_H
#define MODEL_OBJ_CLASS_H

#include <json/json.h>
#include "Core/Mesh.h"

using json = nlohmann::json;


class ModelObj
{
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	ModelObj();
	ModelObj(const char* file, unsigned int instancing = 1, std::vector<glm::mat4> instanceMatrix = {});
/*
protected:

	// Loads a single mesh by its index
	void loadMesh(unsigned int indMesh);

	// Traverses a node recursively, so it essentially traverses all connected nodes
	void traverseNode(unsigned int nextNode, glm::mat4 matrix = glm::mat4(1.0f));

	// Gets the binary data from a file
	std::vector<unsigned char> getData();
	// Interprets the binary data into floats, indices, and textures
	std::vector<float> getFloats(json accessor);
	std::vector<GLuint> getIndices(json accessor);
	std::vector<Texture> getTextures();

	// Helps with the assembly from above by grouping floats
	std::vector<glm::vec2> groupFloatsVec2(std::vector<float> floatVec);
	std::vector<glm::vec3> groupFloatsVec3(std::vector<float> floatVec);
	std::vector<glm::vec4> groupFloatsVec4(std::vector<float> floatVec);*/
};
#endif