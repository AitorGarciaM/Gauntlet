#include "Engine.h"


#include <conio.h>
#include<Windows.h>

int main(int argv, char*args[])
{
	SceneManager* _sceneManager = SceneManager::getInstance();
	Input* _inputManager = Input::getInstance();
	
	Time* _clock = Time::getInstance();

	std::cout << "Hello World!!" << std::endl;
	

	while (!Input::getInstance()->getExit())
	{
		if (_sceneManager->getCurrentScene()->getRestart())
		{
			_sceneManager->getCurrentScene()->setRestart(false);
		}

		_inputManager->update();

		_clock->delay();

		_sceneManager->getCurrentScene()->update();

		if (!_sceneManager->getCurrentScene()->getRestart())
		{
			_sceneManager->getCurrentScene()->render();
		}


	}

	return 0;
}