#ifndef COLLISION_H
#define COLLISION_H

#include <SDL.h>
#include <SDL_image.h>

bool CheckCollisionBetweenTwoTexture(SDL_Rect a, SDL_Rect b)
{
    // Rectangle a
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int bottomA = a.y + a.h;

    // Rectangle b
    int leftB = b.x;
    int rightB = b.x + b.w;
    int topB = b.y;
    int bottomB = b.y + b.h;

    // CheckCollision
    if (bottomA <= topB) {
        return false;
    }

    if (topA >= bottomB) {
        return false;
    }

    if (rightA <= leftB) {
        return false; 
    }

    if (leftA >= rightB) {
        return false;
    }

    return true; 
}
#endif