#pragma once
#include "baseObject.h"
#include "commonBase.h"

class scores {
public:
	scores();
	~scores();
	baseObject score;
	void updateScore(const char* type);
	void renderScore(SDL_Renderer* renderer, SDL_Window* window, SDL_Surface* sur);
	int getScores();
private:
	int scores_count;
};