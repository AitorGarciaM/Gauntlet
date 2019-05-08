#include "Player.h"



Player::Player()
{
	for (int i = 0; i < 4; i++)
	{
		_amo[i] = new Weapon();
	}
}


Player::~Player()
{
}

void Player::init()
{
	_resManager = ResourceManager::getInstance();
	_inputManager = Input::getInstance();
	_audioManager = AudioManager::getInstance();

	_vida = 100;
	_attack = 5;
	_path = "./Resources/Images/entities.png";
	_musicPath = "./Resources/Sounds/Music.mp3";
	_idSprite = _resManager->getTextureID(_path.c_str());

	//_pos.x = WINDOW_WIDTH / 8;
	//_pos.y = WINDOW_HEIGHT / 6;

	_initialFrame = 4;
	_currentFrame = _initialFrame;

	_bounds.x = 0;
	_bounds.y = 0;
	_bounds.w = 32;
	_bounds.h = 32;

	_timeAnimation = 100;
	_time = 0;

	_velocity = _pos;
	_speed = 3;

	_idMusic = _audioManager->getSoundId(_musicPath.c_str());
	_audioManager->playSound(_idMusic, -1);
	
}

void Player::input()
{
	if (_inputManager->getKeyDown(DownArrow))
	{
		_velocity.y += _speed;
	}
	if (_inputManager->getKeyDown(UpArrow))
	{
		_velocity.y -= _speed;
	}
	if (_inputManager->getKeyDown(LeftArrow))
	{
		_velocity.x -= _speed;
	}
	if (_inputManager->getKeyDown(RightArrow))
	{
		_velocity.x += _speed;
	}

	if (_inputManager->getKeyFlagDown(ButtonDownSpace))
	{
		shoot();
	}
}

void Player::update()
{
	windowCollision();
	movement();
	startAnimation();
}

void Player::render()
{

	Vector renderPos = {0,0};

	renderPos.x = _pos.x - _camera->getBounds().x;
	renderPos.y = _pos.y - _camera->getBounds().y;

	std::cout << "Player" << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "X:" << renderPos.x << std::endl;
	std::cout << "Y: " << renderPos.y << std::endl;

	_resManager->DrawInWindow(_idSprite, _bounds, renderPos);
	//for (int i = 0; i < 4; i++)
	//{
		//_amo[i]->render();
	//}
}

void Player::startAnimation()
{
	if (_inputManager->getKeyDown(DownArrow) && _initialFrame != 4 && !_inputManager->getKeyDown(UpArrow) && !_inputManager->getKeyDown(LeftArrow) && !_inputManager->getKeyDown(RightArrow))
	{
		_initialFrame = 4;
		_currentFrame = _initialFrame;
	}
	else if (_inputManager->getKeyDown(UpArrow) && _initialFrame != 0 && !_inputManager->getKeyDown(DownArrow) && !_inputManager->getKeyDown(LeftArrow) && !_inputManager->getKeyDown(RightArrow))
	{
		_initialFrame = 0;
		_currentFrame = _initialFrame;
	}
	else if (_inputManager->getKeyDown(LeftArrow) && _initialFrame != 6 && !_inputManager->getKeyDown(RightArrow) && !_inputManager->getKeyDown(UpArrow) && !_inputManager->getKeyDown(DownArrow))
	{
		_initialFrame = 6;
		_currentFrame = _initialFrame;
	}
	else if (_inputManager->getKeyDown(RightArrow) && _initialFrame != 2 && !_inputManager->getKeyDown(LeftArrow) && !_inputManager->getKeyDown(DownArrow) && !_inputManager->getKeyDown(UpArrow))
	{
		_initialFrame = 2;
		_currentFrame = _initialFrame;
	}
	else if (_inputManager->getKeyDown(DownArrow) && _initialFrame != 5 && _inputManager->getKeyDown(LeftArrow))
	{
		_initialFrame = 5;
		_currentFrame = _initialFrame;
	}
	else if(_inputManager->getKeyDown(UpArrow) && _initialFrame != 7 && _inputManager->getKeyDown(LeftArrow))
	{
		_initialFrame = 7;
		_currentFrame = _initialFrame;
	}
	else if (_inputManager->getKeyDown(UpArrow) && _initialFrame != 1 && _inputManager->getKeyDown(RightArrow))
	{
		_initialFrame = 1;
		_currentFrame = _initialFrame;
	}
	else if (_inputManager->getKeyDown(DownArrow) && _initialFrame != 3 && _inputManager->getKeyDown(RightArrow))
	{
		_initialFrame = 3;
		_currentFrame = _initialFrame;
	}

	if (_inputManager->getKeyDown(DownArrow) || _inputManager->getKeyDown(UpArrow) || _inputManager->getKeyDown(LeftArrow) || _inputManager->getKeyDown(RightArrow))
	{
		animation();
	}
	else
	{
		_bounds.x = _initialFrame * _bounds.w;
	}
}

void Player::animation()
{
	_time += Time::getInstance()->getDeltaTime();

	if (_time >= _timeAnimation)
	{
		if (_currentFrame < (_initialFrame + 15))
		{
			_currentFrame += 8;
		}
		else
		{
			_currentFrame = _initialFrame;
		}

		_time = 0;
	}

	_bounds.x = _currentFrame * _bounds.w;
}

void Player::movement()
{
	_pos.x += _velocity.x;
	_pos.y += _velocity.y;

	_velocity = { 0,0 };
}

void Player::windowCollision()
{
	if (_pos.x <= 0 && _velocity.x < 0)
	{
		_velocity.x = 0;
	}
	if (_pos.x + _bounds.w >= _camera->getBounds().w && _velocity.x > 0)
	{
		_velocity.x = 0;
	}
	if (_pos.y <= 0 && _velocity.y < 0)
	{
		_velocity.y = 0;
	}
	if (_pos.y + _bounds.h >= _camera->getBounds().h && _velocity.y > 0)
	{
		_velocity.y = 0;
	}
}

void Player::shoot()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_amo[i]->getActive())
		{
			_amo[i]->shoot(_pos, _initialFrame);
			break;
		}
	}
}


