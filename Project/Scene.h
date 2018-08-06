#pragma once
#include "Win32_GLAppUtil.h"
#include "shader.h"
#include <iostream>
#include <vector>
struct Scene
{
	struct Menu
	{
		// 0 不开启 1 选择纹理的type 2 选择type对应的具体数值 3 选择大小等
		int status = 0;
		int type = 0;
		int num[2] = { 0 }; // 具体数值
		
		int textureType = 0;
		int speed = 1;
		int size = 1;


		int color = 0;
		int randnum = 0;
		int Type = 0;

		Model *menuModel[2];
		Model *menuSphere;
		Model *pointer;
		Model *Texture;
		~Menu()
		{
			delete menuModel[0];
			delete menuModel[1];
			delete menuSphere;
			delete pointer;
			delete Texture;
		}
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

	void ChangeShader();
	void ChangeColor();
	void drawMenu(Matrix4f view, Matrix4f proj);
	void Render(Matrix4f view, Matrix4f proj, Vector3f pos);
	
	std::vector<Planet *> plants;

	GLuint CreateShader(GLenum type, const char* path);

	void Calculate();
	void Event(int i);
	ShaderFill * generateShader(GLuint vertexShader, GLuint pixelShader, const char * path);
	//ShaderFill * generateShader(GLuint vertexShader, GLuint pixelShader, unsigned char * path);
	//ShaderFill * generateShader();
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

		for (int i = 0; i < 6; i++)
		{
			delete SkyBoxModels[i];
		}

		//glDeleteVertexArrays(1, &SkyBox.skyboxVAO);
		for (auto it = plants.begin(); it != plants.end(); it++)
			delete *it;
	}
	~Scene()
	{
		Release();
	}
};
