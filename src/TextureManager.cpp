#include "TextureManager.h"
#include "SDL_image.h"

TextureManager::TextureManager(SDL_Renderer* renderer)
	:renderer(renderer)
{}

void TextureManager::loadTexture(const std::string path, const std::string id)
{
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());

	if (tmpSurface == nullptr) 
	{
		std::cerr << "Unable to create texture: \"" << id << "\" from path: \"" << path << "\""<< std::endl;

		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);

	if (texture == nullptr) {
		std::cerr << "Unable to create texture from temp surface. Is the renderer correct?" << std::endl;

		return;
	}

	std::cout << id << " texture successfully added" << std::endl;
	textures.emplace(id, texture);
}

void TextureManager::draw(
	std::string id,
	Vector2D transform, 
	const int w, 
	const int h, 
	SDL_RendererFlip flip, 
	const int currentColumn, 
	const int currentRow
)
{
	SDL_Rect src;
	SDL_Rect dest;

	src.x = currentRow * w;
	src.y = currentColumn * h;
	src.w = dest.w = w;
	src.h = dest.h = h;
	dest.x = transform.getX();
	dest.y = transform.getY();

	SDL_RenderCopyEx(renderer, textures.at(id), &src, &dest, 0, 0, flip);
}
