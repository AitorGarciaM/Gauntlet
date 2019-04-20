#include "Enemy.h"


void Enemy::movement()
{
	if (_changeDir)
	{
		_dir = rand() % 8;
		_changeDir = false;
	}

	switch (_dir)
	{
	case 0:
		if (_pos.y <= 0)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { 0,-_speed };
		}
		break;
	case 1:
		if (_pos.y <= 0 || (_pos.x + _bounds.w) >= WINDOW_WIDTH)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { _speed,-_speed };
		}
		break;
	case 2:
		if ((_pos.x + _bounds.w) >= WINDOW_WIDTH)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { _speed,0 };
		}
		break;
	case 3:
		if ((_pos.y + _bounds.h ) >= WINDOW_HEIGHT || (_pos.x + _bounds.w) >= WINDOW_WIDTH)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { _speed,_speed };
		}
		break;
	case 4:
		if ((_pos.y + _bounds.h) >= WINDOW_HEIGHT)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { 0,_speed };
		}
		break;
	case 5:
		if ((_pos.y + _bounds.h) >= WINDOW_HEIGHT || _pos.x <= 0)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { -_speed,_speed };
		}
		break;
	case 6:
		if (_pos.x <= 0)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { -_speed,0 };
		}
		break;
	case 7:
		if (_pos.y <= 0 || _pos.x <= 0)
		{
			_changeDir = true;
		}
		else
		{
			_velocity = { -_speed,-_speed };
		}
		break;
	default:
		break;
	}

	_pos.x += _velocity.x;
	_pos.y += _velocity.y;

}

void Enemy::attack()
{
}

void Enemy::animate()
{
}

void Enemy::init()
{
	srand(time(NULL));
	_resManager = ResourceManager::getInstance();

	_path = "./Resources/Images/entities.png";

	_idSprite = _resManager->getTextureID(_path.c_str());

	_bounds = {0,128,32,32};
	_pos = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

	_speed = 2;

	_velocity = { 0, 0 };
}

void Enemy::update()
{
	movement();
}

void Enemy::render()
{
	_resManager->DrawInWindow(_idSprite, _bounds, _pos);
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
