#pragma once
#include "baseObject.h"
#include "Vector2D.h"

class Player :public baseObject {
public:
	Player();
	float initial_speed = 300.0f;
	void input(SDL_Renderer* renderer,SDL_Window* window, const char* dir, double deltatime);
	void renderLives(SDL_Renderer* renderer, SDL_Window* window);
	void minusLives();
	int getLives();
	baseObject heart1;
	baseObject heart2;
	baseObject heart3;
private:
	int lives = 3;
	int damage_dealt = 30;
};

