#pragma once
#include "Entity.h"
#include "Map.h"
class World
{
	std::vector<Entity*> _entities;
	Map* _map;
public:
	void init();
	void update();
	void render();
	World();
	~World();
};

