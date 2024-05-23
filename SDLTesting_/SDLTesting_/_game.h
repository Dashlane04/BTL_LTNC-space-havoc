#pragma once

#include<time.h>
#include "commonBase.h"
#include "baseObject.h"
#include "Player.h"
#include "_projectile.h"
#include "collision_detection.h"
#include "scores.h"

static SDL_Window* window = SDL_CreateWindow("Space Havoc", SDL_WINDOWPOS_CENTERED, (0x2FFF0000u | (0)), SCREEN_LENGTH, SCREEN_WIDTH, 0);
static SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
static SDL_Event event;
 
const int max_number_enemies = 5;
const int max_bullets = 4;
const int max_asteroids = 10;

class Game {
public:
	Game();
	void GameState();
	void update();
};
