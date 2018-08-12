#pragma once
#include <vector>
#include "Entity.h"
#include "Game.h"

class World {
	private:
		float gravity;
		std::vector<Entity*> entityList;
	public:
		World(float gravity);
		~World();

		void spawnEntity(Entity* e);
		void updateEntities();
		void renderEntities(float interpolation);
		void renderWorld();

		inline float getGravity() { return gravity; }

		std::vector<Entity*> getEntities();
};

