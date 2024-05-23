#pragma once
//compiler specific: pragma once
#include<SDL.h>
#undef main
#include<Windows.h>
#include<iostream>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<string>
#include<math.h>
#include<cmath>
#include<vector>

using namespace std;

void SDL2_Initialize();
	

const int SCREEN_WIDTH = 860;
const int  SCREEN_LENGTH  = 860;
const int SCREEN_BPP = 32; 

static const char* path = "C:/Users/LENOVO/Desktop/Kla'ed - Scout - Base.png";  //Player
static const char* background_path = "C:/Users/LENOVO/Desktop/Space Background.png";  //Background
static const char* _path = "C:/Users/LENOVO/Desktop/Foozle_2DS0015_Void_EnvironmentPack/Asteroids/PNGs/Asteroid 01 - Base.png"; //asteroid
static const char* projectile_path = "C:/Users/LENOVO/Desktop/Nairan - Ray.png";


//
static SDL_Rect* dst_rect;
static SDL_Surface* player_texture_img =  IMG_Load(path);
static SDL_Surface* background_img = IMG_Load(background_path);
static SDL_Surface* projectile_img = IMG_Load(projectile_path);
static SDL_Surface* asteroid_img = IMG_Load(_path);

//Explosion spritesheet (asteroid)
static const char* ex1 = "C:/Users/LENOVO/Desktop/Foozle_2DS0015_Void_EnvironmentPack/Asteroids/PNGs/explode_1.png";
static const char* ex2 = "C:/Users/LENOVO/Desktop/Foozle_2DS0015_Void_EnvironmentPack/Asteroids/PNGs/explode_2.png";
static const char* ex3 = "C:/Users/LENOVO/Desktop/Foozle_2DS0015_Void_EnvironmentPack/Asteroids/PNGs/explode_3.png";
static SDL_Surface* explode_1 = IMG_Load(ex1);
static SDL_Surface* explode_2 = IMG_Load(ex2);
static SDL_Surface* explode_3 = IMG_Load(ex3);


//Player's lives
static const char* full_life = "C:/Users/LENOVO/Desktop/Foozle_2DS0015_Void_EnvironmentPack/Asteroids/PNGs/full_life.png";
static const char* lost_life = "C:/Users/LENOVO/Desktop/Foozle_2DS0015_Void_EnvironmentPack/Asteroids/PNGs/lost_life.png";
static SDL_Surface* life = IMG_Load(full_life);
static SDL_Surface* no_life = IMG_Load(lost_life);









