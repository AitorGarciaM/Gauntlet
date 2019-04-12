#pragma once
#include "Scene.h"
#include "Engine.h"

class GameOver :
	public Scene
{
private:
	Input* _inputManager;
	ResourceManager* _resManager;
	AudioManager* _audioManager;
	Scuare _imageBounds;
	Vector _imagePosition;

	int _idImage;

	void init();
	void reinit();
public:
	void update();
	void render();
	GameOver();
	~GameOver();
};

