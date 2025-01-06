#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"





class Texture {


public:
	Texture LoadTexture(const char* filePath);

private:

	struct TX {
		GLint m_Width = 0, m_Height = 0, m_BitDepth = 0;
		GLuint m_TextureID;
		const char* m_Filelocation;
	};

};