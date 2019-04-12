#include "GameOver.h"
#include "SceneManager.h"



void GameOver::init()
{
	_restart = false;
	_inputManager = Input::getInstance();
	_resManager = ResourceManager::getInstance();
	_audioManager = AudioManager::getInstance();

	_idImage = _resManager->getTextureID("./Resources/Images/PlaceHolderTallyScene.png");

	_imageBounds.x = 0;
	_imageBounds.y = 0;
	_imageBounds.w = WINDOW_WIDTH;
	_imageBounds.h = WINDOW_HEIGHT;

	_imagePosition.x = 0;
	_imagePosition.y = 0;
}

void GameOver::reinit()
{
}

void GameOver::update()
{
}

void GameOver::render()
{
	_resManager->DrawInWindow(_idImage, _imageBounds, _imagePosition);
}

GameOver::GameOver()
{
	init();
}


GameOver::~GameOver()
{
}
