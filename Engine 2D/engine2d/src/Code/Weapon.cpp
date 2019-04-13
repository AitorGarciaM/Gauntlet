#include "Weapon.h"



void Weapon::init()
{
	_path = "./Resources/Images/entities.png";
	_resManager = ResourceManager::getInstance();
	_time = Time::getInstance();

	_idSprite = _resManager->getTextureID(_path.c_str());
	_bounds.x = 24*32;
	_bounds.y = 0;
	_bounds.w = 32;
	_bounds.h = 32;
	_pos.x = 0;
	_pos.y = 0;
	_active = false;
	_speed = 5;
	_velocity = { 0,0 };
	_timeToDespawn = 800;
	_currentTime = 0;
}

void Weapon::update()
{
	if (_active)
	{
		if (_pos.x >= WINDOW_WIDTH || _pos.x < 0 || _pos.y >= WINDOW_HEIGHT || _pos.y < 0)
		{
			_active = false;
			_velocity = { 0,0 };
			_currentTime = 0;
			_bounds.x = 24 * 32;
		}

		_pos.x += _velocity.x;
		_pos.y += _velocity.y;
	}
}

void Weapon::render()
{
	if(_active)
	{
		_resManager->DrawInWindow(_idSprite, _bounds, _pos);
	}
}

void Weapon::shoot(Vector pos, int dir)
{
	if (!_active)
	{
		_pos = pos;
		_active = true;
		
		switch (dir)
		{
		case 0:
			_velocity.y = -_speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 1:
			_velocity.x = _speed;
			_velocity.y = -_speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 2:
			_velocity.x = _speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 3:
			_velocity.x = _speed;
			_velocity.y = _speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 4:
			_velocity.y = +_speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 5: 
			_velocity.x = -_speed;
			_velocity.y = _speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 6:
			_velocity.x = -_speed;
			_bounds.x += _bounds.w * (dir);
			break;
		case 7:
			_velocity.x = -_speed;
			_velocity.y = -_speed;
			_bounds.x += _bounds.w * (dir);
			break;
		default:
			break;
		}
	}
}

Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}
