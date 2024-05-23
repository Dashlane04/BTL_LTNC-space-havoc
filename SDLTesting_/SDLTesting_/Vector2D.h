#pragma once
#include "commonBase.h"

class Vector2D {
public:
	Vector2D();
	Vector2D(float _x,float _y);
	~Vector2D();
	Vector2D* getVec();
	//Operator overiding de thuc hien phep toan vecto
	Vector2D operator+(Vector2D& vec);
	Vector2D operator-(Vector2D& vec);
	//Tim ricochet vecto khi projectile ban vao tuong va bounce
	Vector2D* ricochetVec(bool& collide_x_or_y);
private:
	float x, y;
	int ricochetCount = 0;  //bounce count < 3
};
