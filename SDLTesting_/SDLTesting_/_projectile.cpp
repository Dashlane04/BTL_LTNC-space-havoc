#include "_projectile.h"

Projectile::Projectile(int width, int height, float x, float y,const char* TYPE) {
	obj_box->x = static_cast<int>(x);
	obj_box->y = static_cast<int>(y);
	obj_box->w = width;
	obj_box->h = height;
	this->TYPE = TYPE;
	isAlive = true;
}
Projectile::~Projectile() {
	obj_box_pointer = NULL;
	obj_texture = NULL;
	obj_box = NULL;
}
bool Projectile::checkBounds() {
	if (this->getType() == "ASTEROID" && (obj_box->x >= SCREEN_WIDTH || obj_box->x <= 0 || obj_box->y >= SCREEN_WIDTH || isAlive == false)) {
		return false;
	}
	else if ((this->getType() == "BULLET" || this->getType() == "POWER_BULLET") && (obj_box->x >= SCREEN_WIDTH || obj_box->x <= 0 || obj_box->y <= 0 || obj_box->y >= SCREEN_WIDTH || isAlive == false)) {
		return false;
	}
	return true;
}
const char* Projectile::getType() {
	return this->TYPE;
}
void Projectile::asteroid_update() {
	this->getObject()->y += static_cast<int>(normal_speed);
}
void Projectile::bullet_update() {
	this->getObject()->y -= 5;
}