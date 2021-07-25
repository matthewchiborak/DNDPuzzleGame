#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include<json/json.h>
#include "../IModel.h"

using json = nlohmann::json;


class Model: public IModel
{
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	Model();
	Model(const char* file, unsigned int instancing = 1, std::vector<glm::mat4> instanceMatrix = {});

	void Draw
	(
		Shader& shader,
		Camera& camera,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	) override;

private:
	// Variables for easy access
	const char* file;
	std::vector<unsigned char> data;
	json JSON;
	// Holds number of instances (if 1 the mesh will be rendered normally)
	unsigned int instancing;

	// All the meshes and transformations
	std::vector<Mesh> meshes;
	std::vector<glm::vec3> translationsMeshes;
	std::vector<glm::quat> rotationsMeshes;
	std::vector<glm::vec3> scalesMeshes;
	std::vector<glm::mat4> matricesMeshes;
	std::vector<glm::mat4> instanceMatrix;

	// Prevents textures from being loaded twice
	std::vector<std::string> loadedTexName;
	std::vector<Texture> loadedTex;

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




};
#endif