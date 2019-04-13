#pragma once
#include "Pawn.h"
#include "Weapon.h"
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
	

public:
	Player();
	~Player();
	
	Weapon* getAmo(int pos) { return _amo[pos]; }
	void init();
	void update();
	void render();
};

