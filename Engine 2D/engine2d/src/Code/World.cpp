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
	
	//mapColision();

	for (size_t i = 0; i < _entities.size(); i++)
	{
		
		_entities[i]->update();
	}	

	
}

void World::render(Scuare cameraBounds)
{
	_map->render(cameraBounds);

	for (size_t i = 0; i < _entities.size(); i++)
	{
		_entities[i]->render();
	}
}

void World::mapColision()
{
	Vector playerPos = _entities[_idPlayer]->getPosition();

	Player* tempPlayer = (Player*)_entities[_idPlayer];	
	Vector newPosition = {playerPos.x,playerPos.y};
	Vector playerVelocity;

	playerVelocity = { tempPlayer->getVelocity().x,tempPlayer->getVelocity().y };

	if (playerVelocity.x > 0)
	{
		newPosition.x = playerPos.x + playerVelocity.x / playerVelocity.x;
	}

	if (playerVelocity.y > 0)
	{
		newPosition.y = playerPos.y + playerVelocity.y / playerVelocity.y;
	}
	
	Scuare collision;

	// calculo la posición de las esquinas en el array.
	collision.x = newPosition.x / _map->getTileWidth();
	collision.y = newPosition.y / _map->getTileHeight();
	collision.w = (newPosition.x + tempPlayer->getBounds().w) / _map->getTileWidth();
	collision.h = (newPosition.y + tempPlayer->getBounds().h) / _map->getTileHeight();

	// controlo si la esquina va a una pared.

	int posA; // Esquina arriba izquierda.
	int posB; // Esquina arriba derecha.
	int posC; // Esquina abajo izquierda.
	int posD; // Esquina abajo derecha.

	posA = std::round(collision.y * _map->getMapWidth() + collision.x);
	posB = std::round(collision.y * _map->getMapWidth() + collision.w);
	posC = std::round(collision.h * _map->getMapWidth() + collision.x);
	posD = std::round(collision.h * _map->getMapWidth() + collision.w);

	std::cout << "x: " << collision.x << "\n"
			  << "y: " << collision.y << "\n"
			  << "w: " << collision.w << "\n"
			  << "h: " << collision.h << "\n" 
			  << std::endl;

	if ((_map->getIDData()->at(posA) > 2 && playerVelocity.x < 0) || (_map->getIDData()->at(posC) > 2 && playerVelocity.y > 0) || (_map->getIDData()->at(posB) > 2 && playerVelocity.y < 0) || (_map->getIDData()->at(posD) > 2 && playerVelocity.x > 0))
	{
		tempPlayer->setVelocity({0, 0});
	}
}

World::World()
{
}


World::~World()
{
}
