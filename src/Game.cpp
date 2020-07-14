#include "Game.h"
#include "Config.h"
#include "PlayerActor.h"
#include "EnemyActor.h"
#include "LoaderParams.h"
#include "states\PauseState.h"
#include "states\PlayState.h"
#include "states\GameOverState.h"
#include "Map.h"

void const Game::createGameObjects()
{
	// 4 rows from the bottom of 32px is the ground
	const int groundLevel = Config::HEIGHT - (4 * Config::TILE_HEIGHT);

	player = new PlayerActor{ textureManager, inputHandler, LoaderParams{ "./assets/player.png", "player", 32, 32, 60, groundLevel - 32, 3 } };

	EnemyActor* enemy1 = new EnemyActor{ textureManager, LoaderParams{"./assets/enemy.png", "enemy", 32, 32, 200, groundLevel - 32, 2} };
	gameObjects.push_back(enemy1);

	EnemyActor* enemy2 = new EnemyActor{ textureManager, LoaderParams{"./assets/enemy.png", "enemy", 32, 32, 600, groundLevel - 32, 2}, 150 };
	gameObjects.push_back(enemy2);
}

Game::Game()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Unable to initialize SDL" << std::endl;
	}

	window = SDL_CreateWindow(Config::TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Config::WIDTH, Config::HEIGHT, 0);

	if (window == 0) {
		std::cerr << "Unable to create window" << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == 0) {
		std::cerr << "Unable to create renderer" << std::endl;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	this->init();
}

Game::~Game()
{
	std::cout << "Cleaning up..." << std::endl;

	this->clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Game::init()
{
	camera = { 0, 0, Config::WIDTH / 2, Config::HEIGHT / 2 };
	isRunning = true;
	inputHandler = new InputHandler{};
	textureManager = new TextureManager{ renderer, camera };
	stateManager = new StateManager(new PlayState{});
	collisionManager = new CollisionManager{};

	this->createGameObjects();
	Map map{ textureManager };
	tiles = map.loadMap("./assets/levels/level1.map");
}

void Game::updateCamera()
{
	const int playerX = player->getPosition().getX();
	camera.x = playerX - camera.w;

	if (camera.x < 0) {
		camera.x = 0;
	}

	if (camera.x > camera.w) {
		camera.x = camera.w;
	}
}

void Game::update()
{
	if (isPaused || isGameOver) {
		return;
	}

	this->updateCamera();

	player->update(&camera);

	for (auto& object : gameObjects)
	{
		if (collisionManager->isCollision(player->getRect(), object->getRect())) {
			isGameOver = true;
		}

		object->update(&camera);
	}

	for (auto& tile : tiles)
	{
		tile->update(&camera);
	}

	checkGameOver();
}

void Game::render()
{
	SDL_RenderClear(renderer);

	for (auto& tile : tiles)
	{
		tile->render(textureManager);
	}

	player->render(textureManager);

	stateManager->render();

	for (auto& object : gameObjects)
	{
		object->render(textureManager);
	}

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYUP:
		// escape button used to toggle between play and paused states
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			if (isGameOver) {
				stateManager->pushState(new PlayState{});
				isGameOver = false;
				this->clean();
				this->init();

				return;
			}

			isPaused ? stateManager->pushState(new PlayState{}) : stateManager->pushState(new PauseState{textureManager, camera});
			isPaused = !isPaused;
		}
	}

	inputHandler->handleInput(event);
}

void Game::run()
{
	const int frameDelay = 1000 / Config::FPS;

	while (isRunning) {
		const Uint32 frameStart = SDL_GetTicks();

		this->handleEvents();
		this->update();
		this->render();

		const Uint32 frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void Game::checkGameOver()
{
	if (isGameOver) {
		stateManager->pushState(new GameOverState{textureManager, camera});
	}
}

void Game::clean()
{
	delete inputHandler;
	delete textureManager;
	delete stateManager;
	delete collisionManager;
	delete player;
	gameObjects.clear();
}
