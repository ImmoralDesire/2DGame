#include "MovementController.h"
#include "Game.h"

MovementController::MovementController() {

}


MovementController::~MovementController() {
}

void MovementController::update() {
	this->movingForward = 0;
	this->movingUp = 0;

	if(Game::display.getSettings().keyLeft->isPressed()) {
		this->movingForward -= 1;
	}
	if (Game::display.getSettings().keyRight->isPressed()) {
		this->movingForward += 1;
	}

	if (Game::display.getSettings().keyUp->isPressed()) {
		this->movingUp += 1;
	}
	if (Game::display.getSettings().keyDown->isPressed()) {
		this->movingUp -= 1;
	}

	if (Game::display.getSettings().keySprint->isPressed()) {
		this->movingForward *= 2;
		this->movingUp *= 2;
	}
}
