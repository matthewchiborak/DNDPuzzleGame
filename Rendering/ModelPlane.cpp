#include "ModelPlane.h"

ModelPlane::ModelPlane()
{

}

ModelPlane::ModelPlane(float width, float height, std::string textureFilePath)
{
	this->width = width;
	this->height = height;

	Texture texture((textureFilePath).c_str(), "diffuse", loadedTex.size());
	std::vector<Texture> textures;
	textures.push_back(texture);
	loadedTex.push_back(texture);

	std::vector<float> posVec1 =
	{
		-0.05f, 0.0f, -0.05f,
		-0.05f, 0.0f, 0.05f,
		0.05f, 0.0f, 0.05f
	};
	std::vector<float> posVec2 =
	{
		-0.05f, 0.0f, -0.05f,
		0.05f, 0.0f, 0.05f,
		0.05f, 0.0f, -0.05f
	};
	std::vector<glm::vec3> positions1 = groupFloatsVec3(posVec1);
	std::vector<glm::vec3> positions2 = groupFloatsVec3(posVec2);
	std::vector<float> normalVec =
	{
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};
	std::vector<glm::vec3> normals = groupFloatsVec3(normalVec);
	std::vector<float> texVec1 =
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f
	};
	std::vector<float> texVec2 =
	{
		0.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};
	std::vector<glm::vec2> texUVs1 = groupFloatsVec2(texVec1);
	std::vector<glm::vec2> texUVs2 = groupFloatsVec2(texVec2);

	// Combine all the vertex components and also get the indices and textures
	std::vector<Vertex> vertices1 = assembleVertices(positions1, normals, texUVs1);
	std::vector<GLuint> indices1 = { 0, 2, 1 };
	std::vector<Vertex> vertices2 = assembleVertices(positions2, normals, texUVs2);
	std::vector<GLuint> indices2 = { 0, 2, 1 };

	mesh1 = Mesh(vertices1, indices1, textures, 1, {});
	mesh2 = Mesh(vertices2, indices2, textures, 1, {});
}

void ModelPlane::Draw(Shader& shader, Camera& camera, glm::vec3 translation, glm::quat rotation, glm::vec3 scale)
{
	mesh1.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	mesh2.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
}
