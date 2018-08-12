#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() {
}

TextureManager::~TextureManager() {
}

void TextureManager::init() {
	std::cout << wglGetCurrentContext() << std::endl;
	this->textures["player"] = new Texture("res/anim.png");
	this->textures["world"] = new Texture("res/test.png");

	std::cout << "loaded textures" << std::endl;
}
