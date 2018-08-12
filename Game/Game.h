#pragma once
#include "Display.h"

class Display;

class Game {
	public:
		static Display display;

		Game();
		~Game();

		void init();
};

