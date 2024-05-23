#include  "scores.h"

scores::~scores() {

}
scores::scores() {
	scores_count = 0;
	score.setParams(300, 60, 0, 0);
}
void scores::updateScore(const char* type) {
	if (type == "TIME") {
		scores_count += 10;
	}
	if (type == "HIT") {
		scores_count += 30;
	}
}
void scores :: renderScore(SDL_Renderer* renderer, SDL_Window* window, SDL_Surface* sur) {
	score.renderTextureAndAnimation(renderer, window, sur);
}
int scores::getScores() {
	return this->scores_count;
}