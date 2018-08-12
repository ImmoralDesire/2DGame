#include "World.h"
#include "Texture.h"

World::World(float gravity) : gravity(gravity) {
}

World::~World() {
}

void World::spawnEntity(Entity* e) {
	this->entityList.push_back(e);
}

void World::updateEntities() {
	for (std::vector<Entity*>::iterator it = this->entityList.begin(); it < this->entityList.end(); it++) {
		Entity* e = *it;
		e->update();
	}
}

void World::renderEntities(float interpolation) {
	for (std::vector<Entity*>::iterator it = this->entityList.begin(); it < this->entityList.end(); it++) {
		Entity* e = *it;
		e->render(interpolation);
	}
}

void World::renderWorld() {
	Texture* texture = Game::display.getTextureManager()->getTexture("world");
	texture->bindTexture(0);
	//Texture texture = Game::textureManager.textures["world"];
	texture->render(0, 0, 2048, 2048, 0, 0, 512, 512);
}

std::vector<Entity*> World::getEntities() {
	return this->entityList;
}
