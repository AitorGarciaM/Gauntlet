#include "Game.h"
#include "SceneManager.h"

void Game::init()
{
	_resManager = ResourceManager::getInstance();
	_inputManager = Input::getInstance();
	_audioManager = AudioManager::getInstance();

	_dungeon = new World();
	_camera = new Camera();

	_dungeon->init(_camera);

	_camera->init(_dungeon->getPlayer());
	_camera->setWorldWidth(_dungeon->getWidth());
	_camera->setWorldHeight(_dungeon->getHeight());

	_restart = false;
}

void Game::reinit()
{
	_restart = false;
}

void Game::update()
{
	_dungeon->update();
	_camera->update();	
}

void Game::render()
{
	_dungeon->render(_camera->getBounds());
	ResourceManager::getInstance()->updateWindow();
	ResourceManager::getInstance()->clearWindow();
}

Game::Game()
{

}


Game::~Game()
{
}
