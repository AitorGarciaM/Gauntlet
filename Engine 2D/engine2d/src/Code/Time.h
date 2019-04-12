#pragma once
#include "Core.h"

class Time
{
	static Time* _instance;
	unsigned int lastTime, currentTime, deltaTime;
	float msFrame;
public:
	Time();
	~Time();
	void delay();

	static Time* getInstance();

	unsigned int getDeltaTime()
	{
		return deltaTime;
	}
};

