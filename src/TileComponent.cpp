#include "..\include\TileComponent.h"

TileComponent::TileComponent(const int id, const Vector2D transform, const int w, const int h)
	: transform(transform), width(w), height(h), textureId(id), startingPosition(transform)
{}

void TileComponent::update(SDL_Rect* camera)
{
	transform.setX(startingPosition.getX() - camera->x);
}

void TileComponent::render(TextureManager* textureManager)
{
	std::string textureName;

	switch (textureId) {
	case Tile::NIGHT:
		textureName = "night";
		break;
	case Tile::MUD:
		textureName = "mud";
		break;
	case Tile::GRASS:
		textureName = "grass";
		break;
	}

	textureManager->draw(textureName, transform, width, height);
}

SDL_Rect TileComponent::getRect()
{
	SDL_Rect rect;

	rect.w = width;
	rect.h = height;
	rect.x = transform.getX();
	rect.y = transform.getY();

	return rect;
}
