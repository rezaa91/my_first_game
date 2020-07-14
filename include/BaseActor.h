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
	int lastCameraXPosition = 0;
	SDL_Rect rect;
	Vector2D startingPosition;
public:
	BaseActor(TextureManager* textureManager, const LoaderParams params);
	virtual void update(SDL_Rect* camera) = 0;
	virtual void render(TextureManager* textureManager) = 0;
	Vector2D getPosition();
	SDL_Rect getRect();
};

