#pragma once

#include "Core.h"
#include"Scene.h"

enum SceneName
{
	MENU,PERSONAJE,JUEGO,GAMEOVER,TALLYSCREEN,
	LastScene
};

// Guarda el número total de escenas que tiene nuestro juego.
#define NUMSCENES LastScene

class SceneManager
{
private:
	static SceneManager* _insatance;
	std::vector<Scene*> _scenes; // Guarda todas las escenas del juego.
	SceneName _currentScene; // Guarda que escena está actualmente activa.
	bool _end; // Guarda si el juego tiene que finalizar o no.

/*----------------------funcitons----------------------*/
	void init();
/*-----------------------------------------------------*/
protected:
	SceneManager();
public:
	void changeScene(SceneName nextScene, bool reinit = false);

	Scene* getCurrentScene() { return _scenes[_currentScene]; }
	
	static SceneManager* getInstance();
	~SceneManager();
};

