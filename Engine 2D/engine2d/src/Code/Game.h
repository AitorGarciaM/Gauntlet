#pragma once
#include "Scene.h"
#include "Engine.h"
#include "World.h"
#include "Camera.h"

class Game :
	public Scene
{
private:
	bool _restart;

	Input* _inputManager;
	ResourceManager* _resManager;
	AudioManager* _audioManager;

	

	World* _dungeon;
	Camera* _camera;

	void init();
	void reinit();
public:

	void update();
	void render();
	Game();
	~Game();
};

