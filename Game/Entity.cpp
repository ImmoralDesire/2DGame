#include "Entity.h"

Entity::Entity(float width, float height) : width(width), height(height) {

}

Entity::~Entity() {
}

float Entity::getX() {
	return this->posX;
}

float Entity::getY() {
	return this->posY;
}
