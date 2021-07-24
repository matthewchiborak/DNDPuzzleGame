#ifndef SKYBOX_CLASS_H
#define SKYBOX_CLASS_H

#include <string>

class Skybox
{
public:
	Skybox(std::string textureDirPath, float skyboxVertices[], unsigned int skyboxIndices[]);

	unsigned int get_skyboxVAO(); 
	unsigned int get_skyboxVBO(); 
	unsigned int get_skyboxEBO();
	unsigned int get_cubemapTexture();

protected:
	unsigned int skyboxVAO, skyboxVBO, skyboxEBO;
	std::string facesCubemap[6];
	unsigned int cubemapTexture;
};

#endif