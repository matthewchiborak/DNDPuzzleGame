#include "ModelCube.h"

ModelCube::ModelCube()
{

}

ModelCube::ModelCube(float width, float height, std::string textureFilePath)
{
	this->width = width;
	this->height = height;

	this->elevationOffset = 0.05f;

	makeTop(textureFilePath);
	makeFront(textureFilePath);
	makeRight(textureFilePath);
	makeLeft(textureFilePath);
}

void ModelCube::Draw(Shader& shader, Camera& camera, glm::vec3 translation, glm::quat rotation, glm::vec3 scale)
{
	meshTop1.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshTop2.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshFront1.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshFront2.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshRight1.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshRight2.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshLeft1.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
	meshLeft2.Draw(shader, camera, glm::mat4(1.0f), translation, rotation, scale);
}

void ModelCube::makeTop(std::string textureFilePath)
{
	Texture texture((textureFilePath).c_str(), "diffuse", loadedTex.size());
	std::vector<Texture> textures;
	textures.push_back(texture);
	loadedTex.push_back(texture);

	std::vector<float> posVec1 =
	{
		-0.05f, 0.0f + elevationOffset, -0.05f,
		-0.05f, 0.0f + elevationOffset, 0.05f,
		0.05f, 0.0f + elevationOffset, 0.05f
	};
	std::vector<float> posVec2 =
	{
		-0.05f, 0.0f + elevationOffset, -0.05f,
		0.05f, 0.0f + elevationOffset, 0.05f,
		0.05f, 0.0f + elevationOffset, -0.05f
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

	meshTop1 = Mesh(vertices1, indices1, textures, 1, {});
	meshTop2 = Mesh(vertices2, indices2, textures, 1, {});
}

void ModelCube::makeFront(std::string textureFilePath)
{
	Texture texture((textureFilePath).c_str(), "diffuse", loadedTex.size());
	std::vector<Texture> textures;
	textures.push_back(texture);
	loadedTex.push_back(texture);

	std::vector<float> posVec1 =
	{
		 0.05f, 0.0f + elevationOffset, -0.05f,
		 0.05f, 0.1f + elevationOffset, 0.05f,
		 0.05f, 0.1f + elevationOffset, -0.05f
	};
	std::vector<float> posVec2 =
	{
		0.05f, 0.0f + elevationOffset, -0.05f,
		0.05f, 0.0f + elevationOffset, 0.05f,
		0.05f, 0.1f + elevationOffset, 0.05f
	};
	std::vector<glm::vec3> positions1 = groupFloatsVec3(posVec1);
	std::vector<glm::vec3> positions2 = groupFloatsVec3(posVec2);
	std::vector<float> normalVec =
	{
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f
	};
	std::vector<glm::vec3> normals = groupFloatsVec3(normalVec);
	std::vector<float> texVec1 =
	{
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};
	std::vector<float> texVec2 =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};
	std::vector<glm::vec2> texUVs1 = groupFloatsVec2(texVec1);
	std::vector<glm::vec2> texUVs2 = groupFloatsVec2(texVec2);

	// Combine all the vertex components and also get the indices and textures
	std::vector<Vertex> vertices1 = assembleVertices(positions1, normals, texUVs1);
	std::vector<GLuint> indices1 = { 0, 2, 1 };
	std::vector<Vertex> vertices2 = assembleVertices(positions2, normals, texUVs2);
	std::vector<GLuint> indices2 = { 0, 2, 1 };

	meshFront1 = Mesh(vertices1, indices1, textures, 1, {});
	meshFront2 = Mesh(vertices2, indices2, textures, 1, {});
}

void ModelCube::makeRight(std::string textureFilePath)
{
	Texture texture((textureFilePath).c_str(), "diffuse", loadedTex.size());
	std::vector<Texture> textures;
	textures.push_back(texture);
	loadedTex.push_back(texture);

	std::vector<float> posVec1 =
	{
		 -0.05f, 0.0f + elevationOffset, -0.05f,
		 0.05f, 0.1f + elevationOffset, -0.05f,
		 -0.05f, 0.1f + elevationOffset, -0.05f
	};
	std::vector<float> posVec2 =
	{
		-0.05f, 0.0f + elevationOffset, -0.05f,
		0.05f, 0.0f + elevationOffset, -0.05f,
		0.05f, 0.1f + elevationOffset, -0.05f
	};
	std::vector<glm::vec3> positions1 = groupFloatsVec3(posVec1);
	std::vector<glm::vec3> positions2 = groupFloatsVec3(posVec2);
	std::vector<float> normalVec =
	{
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};
	std::vector<glm::vec3> normals = groupFloatsVec3(normalVec);
	std::vector<float> texVec1 =
	{
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};
	std::vector<float> texVec2 =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};
	std::vector<glm::vec2> texUVs1 = groupFloatsVec2(texVec1);
	std::vector<glm::vec2> texUVs2 = groupFloatsVec2(texVec2);

	// Combine all the vertex components and also get the indices and textures
	std::vector<Vertex> vertices1 = assembleVertices(positions1, normals, texUVs1);
	std::vector<GLuint> indices1 = { 0, 2, 1 };
	std::vector<Vertex> vertices2 = assembleVertices(positions2, normals, texUVs2);
	std::vector<GLuint> indices2 = { 0, 2, 1 };

	meshRight1 = Mesh(vertices1, indices1, textures, 1, {});
	meshRight2 = Mesh(vertices2, indices2, textures, 1, {});
}

void ModelCube::makeLeft(std::string textureFilePath)
{
	Texture texture((textureFilePath).c_str(), "diffuse", loadedTex.size());
	std::vector<Texture> textures;
	textures.push_back(texture);
	loadedTex.push_back(texture);

	std::vector<float> posVec1 =
	{
		 -0.05f, 0.0f + elevationOffset, 0.05f,
		 0.05f, 0.1f + elevationOffset, 0.05f,
		 -0.05f, 0.1f + elevationOffset, 0.05f
	};
	std::vector<float> posVec2 =
	{
		-0.05f, 0.0f + elevationOffset, 0.05f,
		0.05f, 0.0f + elevationOffset, 0.05f,
		0.05f, 0.1f + elevationOffset, 0.05f
	};
	std::vector<glm::vec3> positions1 = groupFloatsVec3(posVec1);
	std::vector<glm::vec3> positions2 = groupFloatsVec3(posVec2);
	std::vector<float> normalVec =
	{
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f
	};
	std::vector<glm::vec3> normals = groupFloatsVec3(normalVec);
	std::vector<float> texVec1 =
	{
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};
	std::vector<float> texVec2 =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};
	std::vector<glm::vec2> texUVs1 = groupFloatsVec2(texVec1);
	std::vector<glm::vec2> texUVs2 = groupFloatsVec2(texVec2);

	// Combine all the vertex components and also get the indices and textures
	std::vector<Vertex> vertices1 = assembleVertices(positions1, normals, texUVs1);
	std::vector<GLuint> indices1 = { 0, 1, 2 };
	std::vector<Vertex> vertices2 = assembleVertices(positions2, normals, texUVs2);
	std::vector<GLuint> indices2 = { 0, 1, 2 };

	meshLeft1 = Mesh(vertices1, indices1, textures, 1, {});
	meshLeft2 = Mesh(vertices2, indices2, textures, 1, {});
}
