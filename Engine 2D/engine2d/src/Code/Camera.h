#pragma once
#include "Engine.h"
#include "Entity.h"

class Camera
{
	Entity* _target;

	Scuare _bounds;

	int _wWorld;
	int _hWorld;
public:

	void init(Entity* target);
	void update();

	void setWorldWidth(int width) { _wWorld = width; }
	void setWorldHeight(int height) { _hWorld = height; }

	Scuare getBounds() { return _bounds; }
	int getWorldWidth() { return _wWorld; }
	int getWorldHeight() { return _hWorld; }
	Camera();
	~Camera();
};

