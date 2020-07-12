#pragma once

#include "SDL.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include <iostream>

class BaseActor
{
protected:
	const std::string id;
	const int width;
	const int height;
	const int numberOfFrames;
	int currentColumn = 0;
	int currentRow = 0;
	Vector2D transform;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
public:
	BaseActor(TextureManager* textureManager, const LoaderParams params);
	virtual void update() = 0;
	virtual void render(TextureManager* textureManager) = 0;
};

