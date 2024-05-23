#include "Player.h"

Player::Player() {
	heart1.setParams(40, 40, 640, 20);
	heart2.setParams(40, 40, 700, 20);
	heart3.setParams(40, 40, 760, 20);
}
void Player::minusLives() {
	this->lives --;
}
void Player::renderLives(SDL_Renderer* renderer, SDL_Window* window) {
	if (this->lives == 3) {
		heart1.renderTextureAndAnimation(renderer, window, life);
		heart2.renderTextureAndAnimation(renderer, window, life);
		heart3.renderTextureAndAnimation(renderer, window, life);
	}
	else if (this->lives == 2) {
		heart1.renderTextureAndAnimation(renderer, window, no_life);
		heart2.renderTextureAndAnimation(renderer, window, life);
		heart3.renderTextureAndAnimation(renderer, window, life);
	}
	else if (this->lives == 1) {
		heart1.renderTextureAndAnimation(renderer, window, no_life);
		heart2.renderTextureAndAnimation(renderer, window, no_life);
		heart3.renderTextureAndAnimation(renderer, window, life);
	}	
}
int Player::getLives() {
	return this->lives;
}
void Player::input(SDL_Renderer* renderer, SDL_Window* window, const char* dir, double deltatime) {
	if (dir == "LEFT" && (obj_box->x > 0)) {
		obj_box->x -= static_cast<int>(initial_speed * deltatime);
	}
	else if (dir == "RIGHT" && (obj_box->x < (SCREEN_LENGTH - obj_box->w))) {
		obj_box->x += static_cast<int>(initial_speed * deltatime);
	}
}







