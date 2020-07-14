#pragma once

#include "TextureManager.h"
#include "TileComponent.h"
#include <vector>

class Map
{
private:
	TextureManager* textureManager = nullptr;
public:
	Map(TextureManager* textureManager);
	std::vector<TileComponent*> loadMap(std::string filePath);
};

