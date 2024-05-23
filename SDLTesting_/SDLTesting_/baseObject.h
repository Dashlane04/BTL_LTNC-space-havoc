#pragma once
#include "commonBase.h"

class baseObject {
public:
	baseObject();
	~baseObject();
	//Them mot function set x,y,w,h cho baseObject
	void setParams(int width, int height, float x, float y);
	void setPos(float a, float b);
	virtual void print();
	SDL_Rect* getObject();
	SDL_Texture* getTextr();
	int current_frame;
	void renderTextureAndAnimation(SDL_Renderer* renderer, SDL_Window* window,  SDL_Surface* surface);
protected:
	SDL_Texture* obj_texture;
	SDL_Rect* obj_box = new SDL_Rect;
	SDL_Rect* obj_box_pointer = obj_box;
};