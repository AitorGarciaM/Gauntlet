#pragma once
#include "Scene.h"
#include "Engine.h"
class TallyScreen :
	public Scene
{
	Input* _inputManager;
	ResourceManager* _resManager;
	AudioManager* _audioManager;
	Scuare _imageBounds;
	Vector _imagePosition;

	int _idImage;

	void init();

	void reinit();
public:
	TallyScreen();
	~TallyScreen();	

	void update();

	void render();
	
};

