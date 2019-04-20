#pragma once
#include "Pawn.h"
class Enemy : public Pawn
{
	ResourceManager* _resManager;
	int _speed;
	int _dir;

	bool _changeDir;

	Vector _velocity;
	Entity* _target;
	Entity* _amo[4];

	void movement();
	void attack();
	void animate();
public:
	void init();
	void update();
	void render();
	void setTarget(Entity* target) { _target = target; }
	Enemy();
	~Enemy();
};

