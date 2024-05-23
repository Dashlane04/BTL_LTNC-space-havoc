#include "commonBase.h"

void SDL2_Initialize() {
	Mix_Init(MIX_INIT_MP3);
	SDL_Init(SDL_INIT_AUDIO);
	if (!SDL_INIT_EVERYTHING) {
		cout << SDL_GetError() << endl;
	}
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}
