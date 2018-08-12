#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>

class Texture {
	public:
		GLuint textureId;
		int width, height;
		
		Texture() {};
		Texture(const char* fileName);
		~Texture();

		void loadTexture(const char* fileName);
		void bindTexture(unsigned int unit);
		void render(int x, int y, int w, int h, float texX, float texY, float texW, float texH);
};

