#include "..\include\Map.h"
#include <fstream>
#include "Config.h"
#include "Vector2D.h"

Map::Map(TextureManager* textureManager)
	:textureManager(textureManager)
{
	textureManager->loadTexture("./assets/night.png", "night");
	textureManager->loadTexture("./assets/grass.png", "grass");
	textureManager->loadTexture("./assets/mud.png", "mud");
}

std::vector<TileComponent*> Map::loadMap(std::string filePath)
{
	char tile;
	std::vector<TileComponent*> tiles;
	std::fstream myFile;
	myFile.open(filePath);

	for (int y = 0; y < Config::MAP_HEIGHT; y++) {
		for (int x = 0; x < Config::MAP_WIDTH; x++) {
			myFile.get(tile);
			tiles.push_back(new TileComponent{tile - '0', Vector2D{x * Config::TILE_WIDTH, y * Config::TILE_HEIGHT}, Config::TILE_WIDTH, Config::TILE_HEIGHT});

			// ignore comma
			myFile.ignore();
		}
	}

	myFile.close();

	return tiles;
}
