#pragma once
#include "Pawn.h"
#include "Weapon.h"
#include "Camera.h"
class Player : public Pawn 
{
	bool _beginAnimation;
	std::string _musicPath;
	ResourceManager* _resManager;
	AudioManager* _audioManager;
	Input* _inputManager;
	Vector _velocity;
	Weapon* _amo[4];
	float _speed;
	int _initialFrame;
	int _idMusic;
	int _currentFrame;

	int _timeAnimation;
	int _time;

	void startAnimation();
	void animation();

	void movement();
	void windowCollision();

	void shoot();

	Camera* _camera;
	

public:
	Player();
	~Player();
	
	void setPosition(Vector position) { _pos = position; }
	void setVelocity(Vector newVelocity) { _velocity = newVelocity; }
	void setCamera(Camera* cam) { _camera = cam; }

	Weapon* getAmo(int pos) { return _amo[pos]; }
	Vector getVelocity() { return _velocity; }
	
	void init();
	void input();
	void update();
	void render();
};

