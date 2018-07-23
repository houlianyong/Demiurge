#pragma once
#include "Win32_GLAppUtil.h"
#include "shader.h"
struct Scene
{
	int     numModels;
	Model * Models[10];

	struct skybox 
	{
		unsigned int cubemapTexture;
		Shader *skyboxShader;
		unsigned int skyboxVAO, skyboxVBO;
	} SkyBox;

	void    Add(Model * n)
	{
		Models[numModels++] = n;
	}

	void Render(Matrix4f view, Matrix4f proj);


	GLuint CreateShader(GLenum type, const char* path);


	void Init(int includeIntensiveGPUobject);

	Scene() : numModels(0) {}
	Scene(bool includeIntensiveGPUobject) :
		numModels(0)
	{
		Init(includeIntensiveGPUobject);
	}
	void Release()
	{
		while (numModels-- > 0)
			delete Models[numModels];
		glDeleteVertexArrays(1, &SkyBox.skyboxVAO);
	}
	~Scene()
	{
		Release();
	}
};
