#include "Camera.h"
#include "Input.h"



void Camera::init(Entity* target)
{
	_target = target;

	_limitInf = 50 * 32;
	_limitSup = 50 * 32;

	_bounds.x = _target->getPosition().x - WINDOW_WIDTH / 2;
	_bounds.y = _target->getPosition().y - WINDOW_HEIGHT / 2;
	_bounds.w = WINDOW_WIDTH;
	_bounds.h = WINDOW_HEIGHT;


}

void Camera::update()
{
	if (_target->getPosition().x > WINDOW_WIDTH / 2) {

		_bounds.x = _target->getPosition().x - WINDOW_WIDTH / 2;
	}
	else
	{
		_bounds.x = 0;
	}
	
	if (_target->getPosition().y > WINDOW_HEIGHT / 2)
	{
		_bounds.y = _target->getPosition().y - WINDOW_HEIGHT / 2;
	}
	else
	{
		_bounds.y = 0;
	}

	if (_target->getPosition().x < _limitInf - WINDOW_WIDTH / 2)
	{
		_bounds.x = _target->getPosition().x - WINDOW_WIDTH / 2;
	}
	else
	{
		_bounds.x = _limitInf - WINDOW_WIDTH;
	}

	if (_target->getPosition().y < _limitSup - WINDOW_HEIGHT / 2)
	{
		_bounds.y = _target->getPosition().y - WINDOW_HEIGHT / 2;
	}
	else
	{
		_bounds.y = _limitSup - WINDOW_HEIGHT;
	}	

	if (_bounds.x < 0)
	{
		_bounds.x = 0;
		_bounds.w = WINDOW_WIDTH;
	}
	if (_bounds.y < 0)
	{
		_bounds.y = 0;
		_bounds.h = WINDOW_HEIGHT;
	}
	if (_bounds.x > _limitInf - WINDOW_WIDTH)
	{
		//_bounds.x = 50 / 2;
		_bounds.x -= 3;
		_bounds.w -= 3;
	}
	if (_bounds.y > _limitSup - WINDOW_HEIGHT)
	{
		_bounds.y -= 1;
		_bounds.h -= 1;
	}
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
