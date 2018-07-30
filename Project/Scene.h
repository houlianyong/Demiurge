#pragma once
#include "Win32_GLAppUtil.h"
#include "shader.h"
struct Scene
{
	struct Menu
	{
		// 0 不开启 1 选择纹理的type 2 选择type对应的具体数值 3 选择大小等
		int status = 0;
		int type = 0;
		int num[2] = { 0 }; // 具体数值

		Model *menuModel;
		Model *menuSphere;
	} menu;

	int     numModels;
	Model * Models[10];
	int numSkyModels;
	Model * SkyBoxModels[6];

	void    Add(Model * n)
	{
		Models[numModels++] = n;
	}
	void    AddSky(Model * n)
	{
		SkyBoxModels[numSkyModels++] = n;
	}

	void ChangeShader(int i);
	void ChangeColor();
	void Render(Matrix4f view, Matrix4f proj);


	GLuint CreateShader(GLenum type, const char* path);

	void Calculate();
	void Init(int includeIntensiveGPUobject);

	Scene() : numModels(0), numSkyModels(0){}
	Scene(bool includeIntensiveGPUobject) :
		numModels(0), numSkyModels(0)
	{
		Init(includeIntensiveGPUobject);
	}
	void Release()
	{
		while (numModels-- > 0)
			delete Models[numModels];
		//glDeleteVertexArrays(1, &SkyBox.skyboxVAO);
	}
	~Scene()
	{
		Release();
	}
};
