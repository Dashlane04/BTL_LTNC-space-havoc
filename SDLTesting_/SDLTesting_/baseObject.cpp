#include "baseObject.h"

baseObject::baseObject() {
	current_frame = 0;
};
baseObject::~baseObject() {
	obj_box_pointer = NULL;
	obj_texture = NULL;
}
 void baseObject::print() {
	cout << "This is the parent class";
}
void baseObject::setPos(float a, float b) {
	obj_box->x = int(a);
	obj_box->y = int(b);
}
void baseObject::setParams(int width, int height, float x, float y) {
	obj_box->w = width;
	obj_box->h = height;
	obj_box->x = int(x);
	obj_box->y = int(y);
};
void baseObject::renderTextureAndAnimation(SDL_Renderer* renderer, SDL_Window* window,  static SDL_Surface* sur) {
	//SDL_Surface* img = IMG_Load(path);
	obj_texture = SDL_CreateTextureFromSurface(renderer, sur);
	dst_rect = new SDL_Rect { obj_box->x,obj_box->y,obj_box->w,obj_box->h };
	SDL_RenderCopy(renderer, obj_texture, NULL, dst_rect);
	SDL_DestroyTexture(obj_texture);
	//SDL_FreeSurface(img);
}
SDL_Rect* baseObject::getObject() { return obj_box; }
SDL_Texture* baseObject::getTextr() { return obj_texture; }