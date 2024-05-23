
#include <SDL.h>
#undef main
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int main(int argc, const char** argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	auto window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
	auto  renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event e;
	enum  Direction {
		DOWN,
		UP,
		LEFT,
		RIGHT
	};
	//Snake head pos
	///
	SDL_Rect head;
	head = {};
	//Snake body container
	///
	deque<SDL_Rect> rq;
	int size = 1;
	//Apple container
	///
	vector<SDL_Rect> apples;
	//Create apples on map
	///
	for (int i = 0; i < 100; i++) {
		apples.emplace_back(rand() % 100 * 10, rand() % 100 * 10, 10, 10);
	}
	bool running = true;
	int dir = 0;

	//MAIN LOOP
	///
	while (running) {
		//Chechk input
		///
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) { running = false; }
			else  if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_DOWN) { dir = DOWN; }
				if (e.key.keysym.sym == SDLK_UP) { dir = UP; }
				if (e.key.keysym.sym == SDLK_LEFT) { dir = LEFT; }
				if (e.key.keysym.sym == SDLK_RIGHT) { dir = RIGHT; }
			}


		}

		//Move snake in dir
		///
		switch (dir) {
		case  DOWN:
			head.y += 10; break;
		case UP:
			head.y -= 10;  break;
		case LEFT:
			head.x -= 10; break;
		case RIGHT:
			head.x += 10; break;
		}

		//Collision detection with apple
		///
		for_each(apples.begin(), apples.end(), [&](auto& apple) {
			if (head.x == apple.x && head.y == apple.y) {
				size += 10;
				apple.x = -10;
				apple.y = -10;
			}
		});
		//Collision detection with snake body
		///
		for_each(rq.begin(), rq.end(), [&](auto& snake_segment) {
			if (head.x == snake_segment.x && head.y == snake_segment.y) {
				size = 1;
			}
			});

		//Add newest head to snake
		rq.push_front(head);

		while (rq.size() > size) {
			rq.pop_back();
		}

		//Clear window
		///
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//Draw body
		///
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		for_each(rq.begin(), rq.end(), [&](auto& snake_segment) {
			SDL_RenderFillRect(renderer, &snake_segment);
			});


		//Display
		///
		SDL_RenderPresent(renderer);
		SDL_Delay(25);

	}
	return 0;
}