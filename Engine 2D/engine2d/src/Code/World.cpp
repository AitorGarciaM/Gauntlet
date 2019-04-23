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

	_mapCollision = _map->getIDData();

	_entities.push_back(tempPlayer);
	_idPlayer = _entities.size() -  1;
	_entities.push_back(tempEnemi);
	Vector initPlayerPos = {_map->getMapWidth(), _map->getMapHeight()};

	tempPlayer->setPosition(initPlayerPos);

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
		_entities[i]->input();
	}
	
	mapColision();

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

void World::mapColision()
{
	Vector playerPos = _entities[_idPlayer]->getPosition();

	Player* tempPlayer = (Player*)_entities[_idPlayer];	
	Vector newPosition;
	Vector playerVelocity;

	playerVelocity = { tempPlayer->getVelocity().x,tempPlayer->getVelocity().y };

	newPosition.x = playerPos.x + playerVelocity.x;
	newPosition.y = playerPos.y + playerVelocity.y;
	
	int posX = 0;
	int posY = 0;

	int id = 0;

	if (tempPlayer->getVelocity().x > 0 || tempPlayer->getVelocity().y > 0)
	{
		posX = (newPosition.x + tempPlayer->getBounds().w) / _map->getTileWidth();
		posY = (newPosition.y + tempPlayer->getBounds().h) / _map->getTileHeight();

		if (tempPlayer->getVelocity().x > 0)
		{
			id = posY * _map->getMapWidth() + posX;
		}
		else if (tempPlayer->getVelocity().y > 0)
		{
			id = posY * _map->getMapWidth() + posX;
		}
	}
	else
	{
		posX = newPosition.x / _map->getTileWidth();
		posY = newPosition.y / _map->getTileHeight();

		id = (posY * _map->getMapWidth() + posX);
	}
	
	if ((_mapCollision->at(id) - 1) > 1)
	{
		tempPlayer->setVelocity(tempPlayer->getVelocity().zero());
	}
}

World::World()
{
}


World::~World()
{
}
