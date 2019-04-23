#include "Camera.h"




void Camera::init(Entity* target)
{
	_target = target;
}

void Camera::update()
{
	_bounds.x = _target->getPosition().x - WINDOW_WIDTH / 2;
	_bounds.y = _target->getPosition().y - WINDOW_HEIGHT / 2;
	_bounds.w = _target->getPosition().x + WINDOW_WIDTH / 2;
	_bounds.h = _target->getPosition().y + WINDOW_HEIGHT / 2;
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
