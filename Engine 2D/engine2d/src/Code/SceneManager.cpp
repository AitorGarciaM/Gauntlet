#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"
#include "TallyScreen.h"

SceneManager* SceneManager::_insatance = NULL;

void SceneManager::init()
{
	/*
	 Llenamos el vector de escenas y los iniciamos.
	*/
	_scenes.resize(NUMSCENES);


	_scenes[MENU] = new Menu();
	_scenes[JUEGO] = new Game();
	_scenes[GAMEOVER] = new GameOver();
	_scenes[TALLYSCREEN] = new TallyScreen();

	_currentScene = MENU;
}

SceneManager::SceneManager()
{
	init();
}

void SceneManager::changeScene(SceneName nextScene, bool reinit)
{
	//_scenes[nextScene]->setRestart(reinit);
	_currentScene = nextScene;
	_scenes[_currentScene]->setRestart(reinit);
}


SceneManager * SceneManager::getInstance()
{
	if (_insatance == NULL)
	{
		_insatance = new SceneManager();
	}

	return _insatance;
}

SceneManager::~SceneManager()
{
}
