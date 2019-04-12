#pragma once
#include "Engine.h"
class Entity
{
protected:
	Vector _pos;
	Scuare _bounds;
	std::string _path;
	int _idSprite;
	bool _active;
public:
	Vector getPosition() { return _pos;    }
	Scuare getBounds()   { return _bounds; }
	bool   getActive()   { return _active; }

	void   setActive(bool value) { _active = value; }

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	
	Entity();
	~Entity();
};

