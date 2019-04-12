#pragma once
#include "Scene.h"
#include "Engine.h"
class Menu :
	public Scene
{
private:
	Input* _inputManager;
	ResourceManager* _resManager;
	AudioManager* _audioManager;
	Scuare _imageBounds;
	Vector _imagePosition;

	int _idImage;

	bool _restart;
	void init();
	void reinit();
public:
	void update();
	void render();
	void setRestart(bool restart) { _restart = restart; }
	Menu();
	~Menu();
};

