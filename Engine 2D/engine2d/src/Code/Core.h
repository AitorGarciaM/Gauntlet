#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<time.h>
#include<string>
#include<SDL.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define FPS 60

enum Keys
{
	DownArrow, UpArrow, LeftArrow, RightArrow,
	Lastkey
};

enum KeysFlagDown
{
	ButtonDownZ, ButtonDownE, ButtonDownSpace,
	LastkeyFlagDown
};

enum KeysFlagUp
{
	ButtonUpZ, ButtonUpE,
	LastkeyFlagUp
};

struct Vector
{
	int x;
	int y;

	Vector zero()
	{
		x = 0; y = 0;
		Vector r = { x, y };

		return r;
	}
};

struct Scuare
{
	int x;
	int y;
	int h;
	int w;
};

#define NUMKEYS  Lastkey
#define NUMKEYSFLAGDOWN LastkeyFlagDown
#define NUMKEYSFLAGUP LastkeyFlagUp