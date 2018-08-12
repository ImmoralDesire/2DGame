#include "Vec2f.h"

Vec2f::~Vec2f() {
}

void Vec2f::add(Vec2f vec) {
	this->x += vec.x;
	this->y += vec.y;
}

void Vec2f::subtract(Vec2f vec) {
	this->x -= vec.x;
	this->y -= vec.y;
}

void Vec2f::multiply(Vec2f vec) {
	this->x *= vec.x;
	this->y *= vec.y;
}

Vec2f Vec2f::normal() {
	return *this;
}