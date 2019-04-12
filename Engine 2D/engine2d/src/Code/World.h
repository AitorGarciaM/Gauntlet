#pragma once
#include "Entity.h"
class World
{
	std::vector<Entity*> _entities;
public:
	void init();
	void update();
	void render();
	World();
	~World();
};

