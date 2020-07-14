#pragma once

#include "Vector2D.h"
#include <iostream>
#include "TextureManager.h"

enum Tile
{
	NIGHT,
	GRASS,
	MUD
};

class TileComponent
{
private:
	const int textureId;
	Vector2D transform;
	const int width;
	const int height;
	Vector2D startingPosition;
public:
	TileComponent(const int, const Vector2D transform, const int w, const int h);
	void update(SDL_Rect* camera);
	void render(TextureManager* textureManager);
	SDL_Rect getRect();
};

