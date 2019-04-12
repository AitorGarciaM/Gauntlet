#include "Menu.h"
#include "SceneManager.h"


void Menu::init()
{
	_restart = false;
	_inputManager = Input::getInstance();
	_resManager = ResourceManager::getInstance();
	_audioManager = AudioManager::getInstance();

	_idImage = _resManager->getTextureID("./Resources/Images/PlaceHolderMenu.png");

	_imageBounds.x = 0;
	_imageBounds.y = 0;
	_imageBounds.w = WINDOW_WIDTH;
	_imageBounds.h = WINDOW_HEIGHT;

	_imagePosition.x = 0;
	_imagePosition.y = 0;
}

void Menu::reinit()
{
}

void Menu::update()
{
	if (_inputManager->getKeyFlagDown(ButtonDownE)) 
	{
		SceneManager::getInstance()->changeScene(JUEGO,true);
	}
}

void Menu::render()
{
	_resManager->DrawInWindow(_idImage, _imageBounds, _imagePosition);
	_resManager->updateWindow();
}

Menu::Menu()
{
	init();
}


Menu::~Menu()
{
}
