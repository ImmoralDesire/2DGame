#pragma once
#include <SDL.h>

class KeyBind {
	public:
		const char* name;
		int key;
		bool state;

		KeyBind(const char* name, SDL_Keycode key);
		~KeyBind();

		bool isPressed() {
			return this->state;
		}
};

