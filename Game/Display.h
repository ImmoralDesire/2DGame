#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Settings.h"
#include "Player.h"
#include "World.h"
#include "Gui.h"
#include "Camera.h"
#include "TextureManager.h"
#include "World.h"

class Player;
class World;
class Gui;
class Camera;
class TextureManager;

class Display {
	protected:
		const char* title;
		int width, height;
		bool loop;
		SDL_Window* window;
		SDL_GLContext context;

		Settings gameSettings;

		Player* player;
		World* world;
		Gui currentScreen;
		Camera* camera;
		TextureManager textureManager;

	public:
		Display();
		virtual ~Display();

		bool running();

		void clear(float r, float g, float b);
		void update();
		void quit();

		void setupOpengl();

		void handleKeyboardInput(int key, bool state);

		void resized();

		inline Settings getSettings() { return this->gameSettings; }

		inline int getWidth() { return this->width; }
		inline int getHeight() { return this->height; }

		inline TextureManager* getTextureManager() { return &this->textureManager; }
		inline World* getWorld() { return this->world; }
		inline Player* getPlayer() { return this->player; }
		inline Camera* getCamera() { return this->camera; }

		void createWindow(const char* title, int width, int height);

		static Display& getInstance() { 
			static Display instance;
			return instance;
		}
};

