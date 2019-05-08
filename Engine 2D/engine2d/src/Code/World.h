#pragma once
#include "Entity.h"
#include "Map.h"
#include "Camera.h"
class World
{
	int _idPlayer;
	std::vector<Entity*> _entities;
	Map* _map;
	std::vector<int>* _mapCollision;
public:
	void init(Camera* cam);
	void update();
	void render(Scuare cameraBounds);
	void mapColision();

	Entity* getPlayer() { return _entities[_idPlayer]; }

	int getWidth() { return _map->getMapWidth(); }
	int getHeight() { return _map->getMapHeight(); }
	World();
	~World();
};

