#pragma once
#include <map>
#include "Texture.h"

class TextureManager {
	public:
		std::map<const char*, Texture*> textures;

		TextureManager();
		~TextureManager();

		void init();

		inline Texture* getTexture(const char* id) { return textures[id]; }
};

