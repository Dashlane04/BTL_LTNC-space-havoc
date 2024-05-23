#pragma once
#include "commonBase.h"
#include "_projectile.h"

bool checkCollision(SDL_Rect* obj1, SDL_Rect* obj2) {
    //The sides of the SDL_Rects
    if (obj1 == NULL || obj2 == NULL) {
        return false;
    }
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    //Calculate the sides of obj1
    leftA = obj1->x;
    rightA = obj1->x + obj1->w;
    topA = obj1->y;
    bottomA = obj1->y + obj1->h;
    //Calculate the sides of obj2
    leftB = obj2->x;
    rightB = obj2->x + obj2->w;
    topB = obj2->y;
    bottomB = obj2->y + obj2->h;
    if (bottomA <= topB)
    {
        return false;
    }
    if (topA >= bottomB)
    {
        return false;
    }
    if (rightA <= leftB)
    {
        return false;
    }
    if (leftA >= rightB)
    {
        return false;
    }
    return true;
}
