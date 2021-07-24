#include "ShaderFlyweightFactory.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

ShaderFlyweightFactory::ShaderFlyweightFactory()
	: IShaderFlyweightFactory()
{
}

Shader* ShaderFlyweightFactory::getFlyweight(std::string key) throw()
{
	if (flyweights.find(key) == flyweights.end())
	{
		return createFlyweight(key);
	}

	return flyweights.at(key);

	throw(key);
}

Shader* ShaderFlyweightFactory::createFlyweight(std::string key) throw()
{
	std::string shaderFilePath = "Rendering/Core/Shaders/";

	if (key == "Default")
	{
		Shader* shader = new Shader((shaderFilePath + "default.vert").c_str(), (shaderFilePath + "default.frag").c_str(), (shaderFilePath + "default.geom").c_str());
		flyweights.insert(std::pair<std::string, Shader*>(key, shader));
		activateShader(shader, true);
		return shader;
	}
	else if (key == "Cutout")
	{
		Shader* shader = new Shader((shaderFilePath + "default.vert").c_str(), (shaderFilePath + "cutout.frag").c_str(), (shaderFilePath + "default.geom").c_str());
		flyweights.insert(std::pair<std::string, Shader*>(key, shader));
		activateShader(shader, true);
		return shader;
	}
	else if (key == "Sky")
	{
		Shader* shader = new ShaderSkybox((shaderFilePath + "skybox.vert").c_str(), (shaderFilePath + "skybox.frag").c_str());
		flyweights.insert(std::pair<std::string, Shader*>(key, shader));
		activateShader(shader, false);
		return shader;
	}

	throw (key);
}

void ShaderFlyweightFactory::activateShader(Shader* shader, bool isLight)
{
	shader->Activate();
	if (isLight)
	{
		//These will be gotten from the model at some pont???????? TODO
		// Take care of all the light related things
		glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		glm::vec3  lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
		glm::mat4 lightModel = glm::mat4(1.0f);
		lightModel = glm::translate(lightModel, lightPos);

		glUniform4f(glGetUniformLocation(shader->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(shader->ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	}
	else
	{
		glUniform1i(glGetUniformLocation(shader->ID, "skybox"), 0);
	}
}
