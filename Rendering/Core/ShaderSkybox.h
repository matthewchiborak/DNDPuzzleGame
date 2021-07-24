#ifndef SHADERSKYBOX_CLASS_H
#define SHADERSKYBOX_CLASS_H

#include "shader.h"

class ShaderSkybox : public Shader
{
public:
	ShaderSkybox();
	ShaderSkybox(const char* vertexFile, const char* fragmentFile);
};

#endif // !SHADERSKYBOX_CLASS_H