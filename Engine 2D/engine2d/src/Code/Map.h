#pragma once
#include "ResourceManager.h"

class Map
{
	ResourceManager* _resManager;
	int _spriteId;

	int _width;
	int _height;
	int _tileWidth;
	int _tileHeight;

	int _firsgid;
	std::string _tileset;
	std::string _data;

	std::vector<int> _idData;
public:
	int getTileWidth() { return _tileWidth; }
	int getTileHeight() { return _tileHeight; }
	int getMapWidth() { return _width; }
	int getMapHeight() { return _height; }
	std::vector<int>* getIDData() { return &_idData; }

	void init();
	void render();
	Map();
	~Map();
};

