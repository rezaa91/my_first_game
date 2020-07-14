#pragma once

#include "SDL.h"
#include "Vector2D.h"
#include <iostream>
#include <map>

class TextureManager
{
private:
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Texture*> textures;
	SDL_Rect& gameCamera;
public:
	TextureManager(SDL_Renderer* renderer, SDL_Rect& gameCamera);
	void loadTexture(const std::string path, const std::string id);
	void draw(
		std::string id,
		Vector2D transform,
		const int w,
		const int h,
		SDL_RendererFlip flip = SDL_FLIP_NONE,
		const int currentColumn = 0,
		const int currentRow = 0
	);
	void removeTexture(const std::string id);
};

