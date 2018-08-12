#pragma once
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include "Vec2f.h"

class Entity {
	protected:
		int id;
		float posX;
		float posY;
		float velX;
		float velY;
		float renderX;
		float renderY;
		float width;
		float height;
		bool onGround;
		Vec2f boundingbox;

	public:
		Entity(float width, float height);
		~Entity();

		float getX();
		float getY();

		virtual void update() = 0;
		virtual void render(float interpolation) = 0;
};

