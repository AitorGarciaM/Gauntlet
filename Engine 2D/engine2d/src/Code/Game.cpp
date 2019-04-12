#include "Game.h"
#include "SceneManager.h"



void Game::init()
{
	_resManager = ResourceManager::getInstance();
	_inputManager = Input::getInstance();
	_audioManager = AudioManager::getInstance();

	_world = new World();

	_world->init();

	_restart = false;
}

void Game::reinit()
{
	_restart = false;
}

void Game::update()
{
	_inputManager->update();

	_world->update();
}

void Game::render()
{
	_world->render();
	ResourceManager::getInstance()->updateWindow();
	//Time::getInstance()->delay();
	ResourceManager::getInstance()->clearWindow();
}

Game::Game()
{
	init();
}


Game::~Game()
{
}
