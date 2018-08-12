#include "KeyBind.h"
#include "Settings.h"

KeyBind::KeyBind(const char* name, SDL_Keycode key) : name(name), key(key), state(false) {
	Settings::keyBinds.push_back(this);
}


KeyBind::~KeyBind() {
}
