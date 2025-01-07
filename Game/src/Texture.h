#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"





class Texture {


public:
	Texture() = default;
	~Texture() {
		if (m_TextureID) {
			glDeleteTextures(1, &m_TextureID);
		}
	}

	void LoadTexture(const char* filePath);

	GLuint GetTextureID() { return m_TextureID; };


private:
	GLint m_Width = 0, m_Height = 0, m_BitDepth = 0;
	GLuint m_TextureID;

};