#include "Camera.h"
#include "Game.h"

Camera::Camera() {
	this->screenX = 0.0f;
	this->screenY = 0.0f;
}


Camera::~Camera() {
}

float Camera::getCameraX() {
	return this->screenX;
}

float Camera::getCameraY() {
	return this->screenY;
}

void Camera::updateCamera() {
	this->screenX = Game::display.getPlayer()->getX();
	this->screenY = Game::display.getPlayer()->getY();
}
