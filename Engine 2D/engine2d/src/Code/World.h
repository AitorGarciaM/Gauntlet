#pragma once
#include "Entity.h"
#include "Map.h"
class World
{
	int _idPlayer;
	std::vector<Entity*> _entities;
	Map* _map;
	std::vector<int>* _mapCollision;
public:
	void init();
	void update();
	void render();
	void mapColision();
	World();
	~World();
};

