#pragma once

#include "SDL.h"

class CollisionManager
{
public:
	bool isCollision(SDL_Rect a, SDL_Rect b);
};
