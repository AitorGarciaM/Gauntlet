#include "Input.h"

Input* Input::_instance = NULL;

void Input::update()
{
	for (int i = 0; i < _keysFlagDown.size(); i++)
	{
		_keysFlagDown[i] = false;
	}

	for (int i = 0; i < _keysFlagUp.size(); i++)
	{
		_keysFlagUp[i] = false;
	}

	while (SDL_PollEvent(&test_event)) {
		switch (test_event.type) {
		case SDL_KEYDOWN:
			if (test_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
			{
				//std::cout << "Left" << std::endl;
				_keys[DownArrow] = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_UP)
			{
				//std::cout << "Right" << std::endl;
				_keys[UpArrow] = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				_salir = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				_keys[RightArrow] = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				_keys[LeftArrow] = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_E) 
			{
				_keysFlagDown[ButtonDownE] = true;
			}
			break;
		case SDL_KEYUP:
			//std::cout << test_event.key.keysym.scancode << std::endl;
			if (test_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
			{
				//std::cout << "Left UP" << std::endl;
				_keys[DownArrow] = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_UP)
			{
				//std::cout << "Right UP" << std::endl;
				_keys[UpArrow] = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				_keys[RightArrow] = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				_keys[LeftArrow] = false;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (test_event.button.button == SDL_BUTTON_LEFT)
			{
				mousePos.x = test_event.motion.x;
				mousePos.y = test_event.motion.y;
				_keys[2] = true;
				std::cout << test_event.motion.x << " " << test_event.motion.y << std::endl;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (test_event.button.button == SDL_BUTTON_LEFT) 
			{
				_keys[2] = false;
			}
			break;
		case SDL_QUIT:
			_salir = true;
			break;
		default:
			break;
		}

	}
}

Input::Input()
{
	_keys.resize(NUMKEYS);
	_keysFlagDown.resize(NUMKEYSFLAGDOWN);
	_keysFlagUp.resize(NUMKEYSFLAGUP);

	_salir = false;
}

Input * Input::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Input();
	}

	return _instance;
}

bool Input::getKeyDown(int idKey)
{
	
	return _keys[idKey];
}

bool Input::getKeyUp(int idKey)
{
	
	return _keys[idKey];
}

bool Input::getKeyFlagDown(int idKey)
{
	return _keysFlagDown[idKey];
}

bool Input::getKeyFlagUP(int idKey)
{
	return _keysFlagUp[idKey];
}

SDL_Rect Input::getMousePos()
{
	return mousePos;
}

bool Input::getExit()
{
	
	return _salir;
}

Input::~Input()
{
}
