#pragma once
#include "stb-master\stb_perlin.h"
#include "stb-master\stb_image_write.h"
class Texture
{
public:
	Texture() {}
	static char* generateTecture(int width, int height, DWORD c, bool type)
	{

		char *texture = new char[width*height * 3];
		for (int i = 0; i < width; i++)
		{
			if (type)
			{
				for (int j = 0; j < height; j++)
				{
					float noise = stb_perlin_noise3(float(i) / width * 10, float(j) / height * 10, 0, 0, 0, 0) / 2 + 0.5;
					texture[3 * (i*width + j)] = ((c >> 0) & 0xff)*noise;
					texture[3 * (i*width + j) + 1] = ((c >> 8) & 0xff)* noise;
					texture[3 * (i*width + j) + 2] = ((c >> 16) & 0xff)* noise;
				}
			}
			else
			{
				float noise = stb_perlin_noise3(float(i) / width * 10, float(0) / height * 10, 0, 0, 0, 0) / 2 + 0.5;
				for (int j = 0; j < height; j++)
				{
					texture[3 * (i*width + j)] = ((c >> 0) & 0xff)*noise;
					texture[3 * (i*width + j) + 1] = ((c >> 8) & 0xff)* noise;
					texture[3 * (i*width + j) + 2] = ((c >> 16) & 0xff)* noise;
				}
			}
		}

		stbi_write_bmp("../../../test.bmp", width, height, 3, texture);
		return texture;
	}
};