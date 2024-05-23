#pragma once
#include "commonBase.h"
#include "baseObject.h"
#include "Vector2D.h"



class Projectile : public baseObject {
public:
	Projectile(int width, int height, float x, float y, const  char* TYPE);
	~Projectile();
	float normal_speed = 6.0f;
	float advanced_speed = 8.0f;
	float hard_speed = 10.0f;
	bool isAlive;
	bool checkBounds();
	void bullet_update();
	void asteroid_update();
	const char* getType();
private:
	Vector2D dir_vec;
	const char* TYPE;
};