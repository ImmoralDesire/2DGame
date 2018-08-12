#include "Display.h"

Mix_Music* music = NULL;

Display::Display() {
	this->player = new Player(95, 95);
	this->world = new World(9.81f);
	this->camera = new Camera();
}


Display::~Display() {
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	IMG_Quit();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Display::createWindow(const char* title, int width, int height) {

	this->title = title;
	this->width = width;
	this->height = height;
	this->loop = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << "Failed to initialized SDL!" << std::endl;
	}

	IMG_Init(IMG_INIT_PNG);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

	Mix_VolumeMusic(20);

	music = Mix_LoadMUS("res/bg.mp3");
	std::cout << Mix_PlayMusic(music, -1) << std::endl;

	window = SDL_CreateWindow(
		this->title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->width,
		this->height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		std::cout << "The window is null??? NANI???" << std::endl;
	}

	SDL_ShowCursor(SDL_DISABLE);

	context = SDL_GL_CreateContext(window);

	setupOpengl();

	SDL_GL_SetSwapInterval(0);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, this->width, 0, this->height, -1.0, 1.0);
	glViewport(0, 0, this->width, this->height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	SDL_GL_SwapWindow(window);
}

void Display::clear(float r, float g, float b) {
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::resized() {
	SDL_GetWindowSize(this->window, &this->width, &this->height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1.0, 1.0);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display::update() {
	SDL_GL_SwapWindow(window);
}

bool Display::running() {
	return this->loop;
}

void Display::quit() {
	this->loop = false;
}

void Display::setupOpengl() {
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Display::handleKeyboardInput(int key, bool state) {
	this->gameSettings.setKeybindState(key, state);
}