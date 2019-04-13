#pragma once
#include "Entity.h"
class Weapon : public Entity
{
	ResourceManager* _resManager;
	int _speed;
	Vector _velocity;
	float _timeToDespawn;
	float _currentTime;
	Time* _time;
public:
	void init();
	void update();
	void render();
	void shoot(Vector pos, int dir);
	Weapon();
	~Weapon();
};

