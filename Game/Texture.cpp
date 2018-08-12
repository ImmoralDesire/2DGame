#include "Texture.h"
#include <iostream>
#include <cassert>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL_image.h>

Texture::Texture(const char* fileName) {
	SDL_Surface* surface = IMG_Load(fileName);

	if (!surface) {
		std::cout << "bruh, error loading image: " << fileName << ". feelsbadman ;(" << std::endl;
	}

	this->width = surface->w;
	this->height = surface->h;

	glGenTextures(1, &textureId);

	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/*glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
	glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);*/

	GLuint mode;

	if (surface->format->BytesPerPixel == 3) mode = GL_RGB;
	else mode = GL_RGBA;

	//std::cout << unsigned(surface->format->BytesPerPixel) << " : " << mode << std::endl;

	//std::cout << SDL_GetError() << std::endl;

	glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

	SDL_FreeSurface(surface);
}

	
Texture::~Texture() {
	glDeleteTextures(1, &textureId);
}

void Texture::loadTexture(const char* fileName) {

}

void Texture::bindTexture(unsigned int unit) {
	assert(unit >= 0 && unit <= 31);

	//glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::render(int x, int y, int w, int h, float texX, float texY, float texW, float texH) {
	glPushMatrix();
	//texture.bindTexture(0);

	texX = texX / this->width;
	texY = texY / this->height;
	texW = texW / this->width;
	texH = texH / this->height;

	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);
	glTexCoord2f(texX, texY); glVertex2f(x, y + h);
	glTexCoord2f(texX + texW, texY); glVertex2f(x + w, y + h);
	glTexCoord2f(texX + texW, texY + texH); glVertex2f(x + w, y);
	glTexCoord2f(texX, texY + texH); glVertex2f(x, y);

	/*glTexCoord2f(0, 0); glVertex2f(x, y + h);
	glTexCoord2f(1, 0); glVertex2f(x + w, y + h);
	glTexCoord2f(1, 1); glVertex2f(x + w, y);
	glTexCoord2f(0, 1); glVertex2f(x, y);*/
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	glPopMatrix();
}
