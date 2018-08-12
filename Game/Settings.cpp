#include "Settings.h"

std::vector<KeyBind*> Settings::keyBinds;
KeyBind* Settings::keyLeft = new KeyBind("left", SDLK_LEFT);
KeyBind* Settings::keyRight = new KeyBind("right", SDLK_RIGHT);
KeyBind* Settings::keyUp = new KeyBind("up", SDLK_UP);
KeyBind* Settings::keyDown = new KeyBind("down", SDLK_DOWN);
KeyBind* Settings::keySprint = new KeyBind("sprint", SDLK_LSHIFT);

Settings::Settings() {
}


Settings::~Settings() {
}

void Settings::setKeybindState(int key, bool state) {
	for (std::vector<KeyBind*>::iterator it = this->keyBinds.begin(); it != this->keyBinds.end(); ++it) {
		KeyBind* b = *it;
		if (b->key == key) {
			b->state = state;
		}
	}
}
