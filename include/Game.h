#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"
#include "BaseActor.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "states\StateManager.h"
#include "TileComponent.h"
#include "CollisionManager.h"

class Game
{
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
	bool isRunning = false;
	std::vector<BaseActor*> gameObjects;
	BaseActor* player;
	InputHandler* inputHandler;
	TextureManager* textureManager;
	StateManager* stateManager;
	bool isPaused = false;
	bool isGameOver = false;
	std::vector<TileComponent*> tiles;
	SDL_Rect camera;
	CollisionManager* collisionManager;

	void const createGameObjects();
public:
	Game();
	~Game();
	void init();
	void updateCamera();
	void update();
	void render();
	void handleEvents();
	void run();
	void checkGameOver();
	void clean();
};

