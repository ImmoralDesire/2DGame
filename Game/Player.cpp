#include "Player.h"
#include "Texture.h"
#include "Game.h"

#define FRAMES 3

int frame;
long timer = 1001;
long prevTimer = 0;

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

Direction dir = Direction::RIGHT;

Player::Player(float width, float height) : Entity(width, height) {
	this->posX = 380;
	this->posY = 380;
	this->velX = 0;
	this->velY = 0;
	//std::cout << "called" << std::endl;
}

Player::~Player() {
}

void Player::update() {
	//std::cout << "CALLED" << std::endl;
	this->movementController.update();
	if (this->movementController.movingForward != 0 || this->movementController.movingUp != 0) {

		if (this->movementController.movingUp > 0) {
			dir = Direction::UP;
		}
		if (this->movementController.movingUp < 0) {
			dir = Direction::DOWN;
		}
		if(this->movementController.movingForward > 0) {
			dir = Direction::RIGHT;
		}
		if (this->movementController.movingForward < 0) {
			dir = Direction::LEFT;
		}

		if(timer > prevTimer + 10) {
			prevTimer = timer;
			frame++;
		}
		this->velX = this->movementController.movingForward * 1.5;
		this->velY = this->movementController.movingUp * 1.5;
	} else {
		this->velX *= 0.6f;
		this->velY *= 0.6f;
	}

	if(abs(this->velX) < 0.01f) {
		this->velX = 0.0f;
	}

	if (abs(this->velY) < 0.01f) {
		this->velY = 0.0f;
	}

	if(this->velX == 0.0f && this->velY == 0.0f) {
		frame = 0;
	}

	timer++;

	this->posX += this->velX;
	this->posY += this->velY;

}

void Player::render(float interpolation) {
	Texture* texture = Game::display.getTextureManager()->getTexture("player");

	texture->bindTexture(0);

	if (frame > FRAMES) {
		frame = 0;
	}

	int viewX = this->posX + (this->velX * interpolation);

	//texture.render(viewX, this->posY + 100, this->width, this->height, frame * 64, 128, 64, 64);

	switch(dir) {
		case Direction::DOWN: {
			texture->render(viewX, this->posY, this->width, this->height, frame * 64, 0, 64, 64);
			break;
		}
		case Direction::LEFT: {
			texture->render(viewX, this->posY, this->width, this->height, frame * 64, 64, 64, 64);
			break;
		}
		case Direction::RIGHT: {
			texture->render(viewX, this->posY, this->width, this->height, frame * 64, 128, 64, 64);
			break;
		}
		case Direction::UP: {
			texture->render(viewX, this->posY, this->width, this->height, frame * 64, 192, 64, 64);
			break;
		}
	}
	//texture.render(this->posX, this->posY + 100, this->width, this->height, 0, 0, 512, 400);
}
