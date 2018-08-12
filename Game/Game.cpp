#include "Game.h"

#define TICKS_PER_SECOND 64
#define SKIP_TICKS 1000 / TICKS_PER_SECOND
#define MAX_FRAMESKIP 5

DWORD next_game_tick = GetTickCount();
int loops;
float interpolation;

Display Game::display;

Game::Game() {
}


Game::~Game() {
}

void Game::init() {
	display.createWindow("Game???", 760, 760);

	display.getTextureManager()->init();
	display.getWorld()->spawnEntity(display.getPlayer());

	while (display.running()) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: {
					display.quit();
					std::cout << "CALLED" << std::endl;
					break;
				}

				case SDL_KEYDOWN: {
					display.handleKeyboardInput(event.key.keysym.sym, true);
					break;
				}

				case SDL_KEYUP: {
					display.handleKeyboardInput(event.key.keysym.sym, false);
					break;
				}

				case SDL_WINDOWEVENT: {
					if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
						display.resized();
					}
					break;
				}
			}
		}

		loops = 0;
		while (GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP) {
			//player.update();
			//std::cout << display.getWorld()->getGravity() << std::endl;
			display.getWorld()->updateEntities();
			//display.getWorld().updateEntities();

			next_game_tick += SKIP_TICKS;
			loops++;
		}

		std::cout << display.getCamera()->getCameraX() << " : " << display.getCamera()->getCameraY() << std::endl;
		interpolation = float(GetTickCount() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);

		display.getCamera()->updateCamera();
		
		glPushMatrix();
		glTranslatef(-display.getCamera()->getCameraX(), -display.getCamera()->getCameraY(), 0.0f);
		display.clear(0.5f, 0, 0.5f);
		display.getWorld()->renderWorld();
		//glTranslatef(display.getCamera()->getCameraX(), display.getCamera()->getCameraY(), 0.0f);
		glTranslatef(380.0f, 380.0f, 0.0f);
		display.getWorld()->renderEntities(interpolation);
		glPopMatrix();
		//std::cout << interpolation << std::endl;
		display.update();
	}
}
