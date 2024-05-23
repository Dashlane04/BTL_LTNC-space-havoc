#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}
Vector2D::Vector2D() {
	this->x = 0;
	this->y = 0;
}
Vector2D::~Vector2D() {

}
Vector2D* Vector2D::getVec() {
	return this;
}
Vector2D Vector2D::operator+(Vector2D& vec){
	Vector2D res;
	res.x = this->x + vec.x;
	res.y = this->y + vec.y;
	return res;
}
Vector2D Vector2D::operator-(Vector2D& vec) {
	Vector2D res;
	res.x = this->x - vec.x;
	res.y = this->y - vec.y;
	return res;
}
Vector2D* Vector2D::ricochetVec(bool& collide_x_or_y) {
	if (collide_x_or_y == true) {   //Collide vao trai hoac phai
		this->x = -this->x;
		return this;
	}
	if (collide_x_or_y == false) {   //Collide vao tren hoac duoi
		this->y = -this->y;
		return this;
	}
}
