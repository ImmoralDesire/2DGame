#pragma once
#include <vector>
#include "KeyBind.h"

class Settings {
public:
	Settings();
	~Settings();

	void setKeybindState(int key, bool state);

	static std::vector<KeyBind*> keyBinds;
	static KeyBind* keyLeft;
	static KeyBind* keyRight;
	static KeyBind* keyUp;
	static KeyBind* keyDown;
	static KeyBind* keySprint;
};

