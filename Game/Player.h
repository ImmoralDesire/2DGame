#pragma once
#include <iostream>
#include "Entity.h"
#include "MovementController.h"

class Player : virtual public Entity {
	private:
	public:
		Player(float width, float height);
		~Player();

		MovementController movementController;

		virtual void update();
		virtual void render(float interpolation);
};

