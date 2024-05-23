#include  "_game.h"
//FPS va frametime de tao animation
int frameTime = 0;
const double TIME_CONSTANT = 0.016;      //60 FPS/SEC
const Uint32 shot_wait_duration = 500;
const Uint32 asteroid_interval = 100;
Uint32 BULLET_NOW, BULLET_LAST, ASTEROID_NOW, ASTEROID_LAST;
Uint32 delta_time_bullet, delta_time_asteroid;
bool spawn_command = true;


//loop game
bool is_game_running = false;
scores new_score;
bool isMinused = false;


//Khoi tao Map va Player instance, chua render
Player player;
baseObject background;
std::vector<Projectile> projectiles;
vector<Projectile>::iterator it = projectiles.begin();

Game::Game() {
	is_game_running = true;
	
	background.setParams(SCREEN_LENGTH, SCREEN_WIDTH, 0, 0);
	SDL_WarpMouseInWindow(window, SCREEN_WIDTH / 2, SCREEN_LENGTH / 2);
	(player).setParams(60, 60, SCREEN_LENGTH / 2, SCREEN_WIDTH - 70*2);

}
void Game::update() {
	//RENDER STUFF
	SDL_RenderClear(renderer);

	background.renderTextureAndAnimation(renderer, window, background_img);
	(player).renderTextureAndAnimation(renderer, window, player_texture_img);
	player.renderLives(renderer, window);
	
	
	//CHECK COLLISION
	int vector_size = projectiles.size();
	bool isCollided = false;

	for (int i = 0; i < projectiles.size(); i++) {
		for (int j = 0; j < projectiles.size(); j++) {
			if (i != j && projectiles[i].getType() == "BULLET" && projectiles[j].getType() == "ASTEROID") {
				if (checkCollision(projectiles[i].getObject(), projectiles[j].getObject())) {
					projectiles[j].renderTextureAndAnimation(renderer, window, explode_1);
					projectiles[j].renderTextureAndAnimation(renderer, window, explode_2);
					projectiles[j].renderTextureAndAnimation(renderer, window, explode_3);
					new_score.updateScore("HIT");
					projectiles[i].isAlive = false;
					projectiles[j].isAlive = false;
				}
			}
		}
	}

	
	for (int i = 0; i < projectiles.size(); i++) {
		if (projectiles[i].isAlive == true) {
			if (projectiles[i].getType() == "BULLET") {
				projectiles[i].bullet_update();
				projectiles[i].renderTextureAndAnimation(renderer, window, projectile_img);
			}
			else if (projectiles[i].getType() == "ASTEROID") {
				projectiles[i].asteroid_update();
				projectiles[i].renderTextureAndAnimation(renderer, window, asteroid_img);
				if (checkCollision(player.getObject(), projectiles[i].getObject())) {
					if (projectiles[i].isAlive == true) {
						projectiles[i].isAlive = false;
						player.minusLives();
					}
				}
			}

			if (projectiles[i].checkBounds() == false) {
				projectiles[i].~Projectile();
				projectiles[i].isAlive = false;
			}
		}
		
		//Remove first object in projectiles if not alive -> keep size in check
		if (i == 0 && projectiles[i].isAlive == false) {
			projectiles.erase(projectiles.begin());
		}
		
	};
	if (player.getLives() < 1) {
		is_game_running = false;
		cout << "HIGH_SCORE: " << new_score.getScores();
	}
	
}

void Game::GameState() {

}

int main(int argc, char** argv) {
	SDL2_Initialize();

	Game game;

	BULLET_LAST = 0;
	ASTEROID_LAST = 0;

	int x;
	float r;
	srand(static_cast<unsigned int>(time(nullptr)));
	
	while (is_game_running) {

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

		BULLET_NOW = SDL_GetTicks();
		ASTEROID_NOW = SDL_GetTicks();

		frameTime++;

		while (SDL_PollEvent(&event) != 0)
		{
			//User requests quit
			if (event.type == SDL_QUIT)
			{
				SDL_Quit();
			}
		}

		//GET KEYBOARD INPUT
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		 if (currentKeyStates[SDL_SCANCODE_LEFT])
		{
			 (player).input(renderer, window, "LEFT", TIME_CONSTANT);
		}
		else if (currentKeyStates[SDL_SCANCODE_RIGHT])
		{
			 (player).input(renderer, window, "RIGHT", TIME_CONSTANT);	
		}

		//SPAWN ASTEROID + BULLET (ON SPACE PRESS)
		 delta_time_bullet = BULLET_NOW - BULLET_LAST;
		 delta_time_asteroid = ASTEROID_NOW - ASTEROID_LAST;
		if (delta_time_bullet > shot_wait_duration && currentKeyStates[SDL_SCANCODE_SPACE]) {
			projectiles.emplace_back(20, 30, (player).getObject()->x + ((player).getObject()->w / 2) - 10, (player).getObject()->y - 20, "BULLET");
			BULLET_LAST = BULLET_NOW;
		}
		if (delta_time_asteroid > asteroid_interval && spawn_command == true) {
			new_score.updateScore("TIME");
			x = static_cast<int>(float(SCREEN_LENGTH) * r);
			projectiles.emplace_back(70, 70, x, -80, "ASTEROID");
			ASTEROID_LAST = ASTEROID_NOW;
		}
		
		game.update();
		
		SDL_RenderPresent(renderer);

		
	}
	SDL_Quit();
    return 0;
}