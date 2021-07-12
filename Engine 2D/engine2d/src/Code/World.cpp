#include "World.h"
#include "Player.h"
#include "Enemy.h"



void World::init(Camera* cam)
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
	Vector initPlayerPos = {32, 32};

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
	
	tempPlayer->setCamera(cam);

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
	Vector currentPlayerPos = _entities[_idPlayer]->getPosition();

	Player* tempPlayer = (Player*)_entities[_idPlayer];	
	Vector nextPlayerPosition = {currentPlayerPos.x,currentPlayerPos.y};
	Vector playerVelocity;

	playerVelocity = { tempPlayer->getVelocity().x,tempPlayer->getVelocity().y };

	if (playerVelocity.x > 0)
	{
		nextPlayerPosition.x = currentPlayerPos.x + tempPlayer->getSpeed();
	}
	else if (playerVelocity.x < 0)
	{
		nextPlayerPosition.x = currentPlayerPos.x - tempPlayer->getSpeed();
	}

	if (playerVelocity.y > 0)
	{
		nextPlayerPosition.y = currentPlayerPos.y + tempPlayer->getSpeed();
	}
	else if (playerVelocity.y < 0)
	{
		nextPlayerPosition.y = currentPlayerPos.y - tempPlayer->getSpeed();
	}
	
	Scuare collision;

	// calculo la posición de las esquinas en el array.
	collision.x = (nextPlayerPosition.x) / _map->getTileWidth();
	collision.y = (nextPlayerPosition.y) / _map->getTileHeight();
	collision.w = (nextPlayerPosition.x + (tempPlayer->getBounds().w)) / _map->getTileWidth();
	collision.h = (nextPlayerPosition.y + (tempPlayer->getBounds().h)) / _map->getTileHeight();

	// controlo si la esquina va a una pared.

	int posA; // Esquina arriba izquierda.
	int posB; // Esquina arriba derecha.
	int posC; // Esquina abajo izquierda.
	int posD; // Esquina abajo derecha.

	posA = std::round(collision.y * _map->getMapWidth() + collision.x);
	posB = std::round(collision.y * _map->getMapWidth() + collision.w);
	posC = std::round(collision.h * _map->getMapWidth() + collision.x);
	posD = std::round(collision.h * _map->getMapWidth() + collision.w);

	std::cout << "posA " << posA << ": " << _map->getIDData()->at(posA) << "\n"
			  << "posB " << posB << ": " << _map->getIDData()->at(posB) << "\n"
			  << "posC " << posC << ": " << _map->getIDData()->at(posC) << "\n"
			  << "posD " << posD << ": " << _map->getIDData()->at(posD) << "\n"
			  << std::endl;

	// Checks if player is colliding at left.
	if (playerVelocity.x < 0 && (_map->getIDData()->at(posA) > 2 || _map->getIDData()->at(posC) > 2))
	{
		tempPlayer->setVelocity({ 0, 0});
	}
	// Checks if player is colliding at right
	if (playerVelocity.x > 0 && (_map->getIDData()->at(posB) > 2 || _map->getIDData()->at(posD) > 2))
	{
		tempPlayer->setVelocity({ 0, 0});
	}
	// Checks if player is colliding at down
	if (playerVelocity.y > 0 && (_map->getIDData()->at(posC) > 2 || _map->getIDData()->at(posD) > 2))
	{
		tempPlayer->setVelocity({ 0, 0 });
	}
	// Checks if player is colliding at up.
	if (playerVelocity.y < 0 && (_map->getIDData()->at(posA) > 2 || _map->getIDData()->at(posB) > 2))
	{
		tempPlayer->setVelocity({ 0, 0 });
	}
}

World::World()
{
}


World::~World()
{
}
