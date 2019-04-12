#include "Time.h"

Time* Time::_instance = NULL;

Time::Time()
{
	lastTime = 0;
	currentTime = 0;
	deltaTime = 0;
	msFrame = 1 / (FPS / 1000.0f);
}


Time::~Time()
{
}

void Time::delay()
{
	currentTime = SDL_GetTicks();
	deltaTime = currentTime - lastTime;

	//std::cout << deltaTime << std::endl;

	if (deltaTime < (int)msFrame)
	{
		SDL_Delay((int)msFrame - deltaTime);
	}

	lastTime = currentTime;
}

Time * Time::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Time();
	}

	return _instance;
}
