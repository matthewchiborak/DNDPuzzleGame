#include "GameWindow.h"

#include <math.h>





GameWindow::GameWindow(IRenderer* initialRenderer)
	: IGameWindow(initialRenderer)
{
	setUp();
}

void GameWindow::draw()
{
	//renderer.draw(); or w/e
	// Updates counter and times
	crntTime = glfwGetTime();
	timeDiff = crntTime - prevTime;
	counter++;

	if (timeDiff >= 1.0 / 30.0)
	{
		// Creates new title
		std::string FPS = std::to_string((int)((1.0 / timeDiff) * counter));
		std::string newTitle = "YoutubeOpenGL - " + FPS + " FPS";
		glfwSetWindowTitle(window, newTitle.c_str());

		// Resets times and counter
		prevTime = crntTime;
		counter = 0;

		// Use this if you have disabled VSync
		//camera.Inputs(window);
	}

	// Bind the custom framebuffer
	//glBindFramebuffer(GL_FRAMEBUFFER, FBO);
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Enable depth testing since it's disabled when drawing the framebuffer rectangle
	//glEnable(GL_DEPTH_TEST);

	// Handles camera inputs
	//camera.Inputs(window);
	// Updates and exports the camera matrix to the Vertex Shader
	camera.updateMatrix(45.0f, 0.1f, 100.0f);

	// Draw a model
	model.Draw(shaderProgram, camera);

	///////////////////////////////////////
	// Since the cubemap will always have a depth of 1.0, we need that equal sign so it doesn't get discarded
	glDepthFunc(GL_LEQUAL);

	skyboxShader.Activate();
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	// We make the mat4 into a mat3 and then a mat4 again in order to get rid of the last row and column
	// The last row and column affect the translation of the skybox (which we don't want to affect)
	view = glm::mat4(glm::mat3(glm::lookAt(camera.Position, camera.Position + camera.Orientation, camera.Up)));
	projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	// Draws the cubemap as the last object so we can save a bit of performance by discarding all fragments
	// where an object is present (a depth of 1.0f will always fail against any object's depth value)
	glBindVertexArray(skyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// Switch back to the normal depth function
	glDepthFunc(GL_LESS);
	///////////////////////

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	// Take care of all GLFW events
	glfwPollEvents();
}

void GameWindow::clearMemory()
{
	// Delete all the objects we've created
	shaderProgram.Delete();
	grassProgram.Delete();
	skyboxShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void GameWindow::setUp()
{
	// Vertices coordinates
	/*skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(1.0f);

	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(1.0f);

	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(-1.0f);

	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(-1.0f);

	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(1.0f);

	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(1.0f);

	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(-1.0f);

	skyboxVertices.push_back(-1.0f);
	skyboxVertices.push_back(1.0f);
	skyboxVertices.push_back(-1.0f);

	//////////
	skyboxIndices.push_back(1);
	skyboxIndices.push_back(2);
	skyboxIndices.push_back(6);
	skyboxIndices.push_back(6);
	skyboxIndices.push_back(5);
	skyboxIndices.push_back(1);

	skyboxIndices.push_back(0);
	skyboxIndices.push_back(4);
	skyboxIndices.push_back(7);
	skyboxIndices.push_back(7);
	skyboxIndices.push_back(3);
	skyboxIndices.push_back(0);

	skyboxIndices.push_back(4);
	skyboxIndices.push_back(5);
	skyboxIndices.push_back(6);
	skyboxIndices.push_back(6);
	skyboxIndices.push_back(7);
	skyboxIndices.push_back(4);

	skyboxIndices.push_back(0);
	skyboxIndices.push_back(3);
	skyboxIndices.push_back(2);
	skyboxIndices.push_back(2);
	skyboxIndices.push_back(1);
	skyboxIndices.push_back(0);

	skyboxIndices.push_back(0);
	skyboxIndices.push_back(1);
	skyboxIndices.push_back(5);
	skyboxIndices.push_back(5);
	skyboxIndices.push_back(4);
	skyboxIndices.push_back(0);

	skyboxIndices.push_back(3);
	skyboxIndices.push_back(7);
	skyboxIndices.push_back(6);
	skyboxIndices.push_back(6);
	skyboxIndices.push_back(2);
	skyboxIndices.push_back(3);*/

	///////////////////
	float skyboxVertices[] =
	{
		//   Coordinates
		-1.0f, -1.0f,  1.0f,//        7--------6
		 1.0f, -1.0f,  1.0f,//       /|       /|
		 1.0f, -1.0f, -1.0f,//      4--------5 |
		-1.0f, -1.0f, -1.0f,//      | |      | |
		-1.0f,  1.0f,  1.0f,//      | 3------|-2
		 1.0f,  1.0f,  1.0f,//      |/       |/
		 1.0f,  1.0f, -1.0f,//      0--------1
		-1.0f,  1.0f, -1.0f
	};

	unsigned int skyboxIndices[] =
	{
		// Right
		1, 2, 6,
		6, 5, 1,
		// Left
		0, 4, 7,
		7, 3, 0,
		// Top
		4, 5, 6,
		6, 7, 4,
		// Bottom
		0, 3, 2,
		2, 1, 0,
		// Back
		0, 1, 5,
		5, 4, 0,
		// Front
		3, 7, 6,
		6, 2, 3
	};

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Only use this if you don't have a framebuffer
	glfwWindowHint(GLFW_SAMPLES, samples);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Generates Shader object using shaders default.vert and default.frag
	std::string shaderFilePath = "Rendering/Core/Shaders/";
	shaderProgram = Shader((shaderFilePath + "default.vert").c_str(), (shaderFilePath + "default.frag").c_str(), (shaderFilePath + "default.geom").c_str());
	grassProgram = Shader((shaderFilePath + "default.vert").c_str(), (shaderFilePath + "cutout.frag").c_str(), (shaderFilePath + "default.geom").c_str());
	skyboxShader = ShaderSkybox((shaderFilePath + "skybox.vert").c_str(), (shaderFilePath + "skybox.frag").c_str());

	// Take care of all the light related things
	lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	grassProgram.Activate();
	glUniform4f(glGetUniformLocation(grassProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(grassProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	skyboxShader.Activate();
	glUniform1i(glGetUniformLocation(skyboxShader.ID, "skybox"), 0);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	//Gamma correction
	//glEnable(GL_FRAMEBUFFER_SRGB);

	// Enables Multisampling
	glEnable(GL_MULTISAMPLE);

	// Enables Cull Facing
	glEnable(GL_CULL_FACE);
	// Keeps front faces
	glCullFace(GL_FRONT);
	// Uses counter clock-wise standard
	glFrontFace(GL_CCW);
	// Configures the blending function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Creates camera object
	camera = Camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Load in a model
	model = Model("models/bunny/scene.gltf");
	grass = Model("models/grass/scene.gltf");

	// Variables to create periodic event for FPS displaying
	prevTime = 0.0;
	crntTime = 0.0;
	timeDiff;
	// Keeps track of the amount of frames in timeDiff
	counter = 0;

	// Use this to disable VSync (not advized)
	//glfwSwapInterval(0);

	
	// Create VAO, VBO, and EBO for the skybox
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glGenBuffers(1, &skyboxEBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, skyboxEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(skyboxIndices), &skyboxIndices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// All the faces of the cubemap (make sure they are in this exact order)
	facesCubemap[0] = "Textures/skybox/right.jpg";
	facesCubemap[1] = "Textures/skybox/left.jpg";
	facesCubemap[2] = "Textures/skybox/top.jpg";
	facesCubemap[3] = "Textures/skybox/bottom.jpg";
	facesCubemap[4] = "Textures/skybox/front.jpg";
	facesCubemap[5] = "Textures/skybox/back.jpg";

	// Creates the cubemap texture object
	glGenTextures(1, &cubemapTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// These are very important to prevent seams
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	// This might help with seams on some systems
	//glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	// Cycles through all the textures and attaches them to the cubemap object
	for (unsigned int i = 0; i < 6; i++)
	{
		int width, height, nrChannels;
		unsigned char* data = stbi_load(facesCubemap[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			stbi_set_flip_vertically_on_load(false);
			glTexImage2D
			(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0,
				GL_RGB,
				width,
				height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				data
			);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Failed to load texture: " << facesCubemap[i] << std::endl;
			stbi_image_free(data);
		}
	}
	

}
