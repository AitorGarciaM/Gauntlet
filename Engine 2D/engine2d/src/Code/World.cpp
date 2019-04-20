#include "World.h"
#include "Player.h"
#include "Enemy.h"



void World::init()
{
	// hacer una clase para cargar las entidades por código mediante un xml.

	Player* tempPlayer = new Player();
	Weapon* tempAmo;
	Enemy* tempEnemi = new Enemy();
	_map = new Map();

	_map->init();

	_entities.push_back(tempPlayer);
	_entities.push_back(tempEnemi);

	for(int i = 0; i < 4; i++)
	{
		tempAmo = tempPlayer->getAmo(i);
		_entities.push_back(tempAmo);
	}


	for (int i = 0; i < _entities.size(); i++)
	{
		_entities[i]->init();
	}
	
}

void World::update()
{
	for (size_t i = 0; i < _entities.size(); i++)
	{
		_entities[i]->update();
	}	
}

void World::render()
{
	_map->render();

	for (size_t i = 0; i < _entities.size(); i++)
	{
		_entities[i]->render();
	}
}

World::World()
{
}


World::~World()
{
}
