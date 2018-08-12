#pragma once
#include "Entity.h"

class Ball : virtual public Entity {
	public:
		Ball(float width, float height);
		~Ball();

		virtual void update();
		virtual void render(float interpolation);
};

