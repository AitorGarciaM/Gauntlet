#include "ResourceManager.h"

ResourceManager* ResourceManager::_instance = NULL;

Uint32 ResourceManager::addTexture(const char * path)
{
	SDL_Texture* loadedTexture = IMG_LoadTexture(_renderer, path);

	if (loadedTexture == NULL)
	{
		std::cout << "Error Img: " << IMG_GetError() << std::endl;
	}

	if (_firstFreeSlot < _textureVector.size())
	{
		Uint32 id = _firstFreeSlot;
		_firstFreeSlot = _textureVector.size();
		_textureVector[id] = loadedTexture;
		
		return id;
	}
	else
	{
		_textureVector.push_back(loadedTexture);
		_firstFreeSlot = _textureVector.size();

		return _firstFreeSlot - 1;
	}
}

void ResourceManager::updateFirstFreeSlot()
{
	for (int i = 0; i < _textureVector.size(); i++)
	{
		if (_textureVector[i] == NULL) 
		{
			_firstFreeSlot = i;
		}
	}
}

ResourceManager::ResourceManager()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	_window = SDL_CreateWindow("Gauntlet", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);	
}


ResourceManager * ResourceManager::getInstance()
{
	if(_instance == NULL)
	{
		_instance = new ResourceManager();
	}

	return _instance;
}

Uint32 ResourceManager::getTextureID(const char* path)
{
	
	std::map<std::string, Uint32>::iterator it = _idMap.find(path);
	if (it == _idMap.end())
	{
		Uint32 id = addTexture(path);
		_idMap[path] = id;
	}

	return _idMap[path];
}

void ResourceManager::removeTexture(const char * path)
{
	std::map<std::string, Uint32>::iterator it = _idMap.find(path);

	if (it == _idMap.end())
	{
		std::cout << "El archivo no existe!" << std::endl;
	}
	else
	{
		_textureVector[it->second] = NULL;
		_idMap.erase(path);
		updateFirstFreeSlot();
	}
}

SDL_Texture * ResourceManager::getTextureBYId(Uint32 id)
{
	return _textureVector[id];
}
/**/
void ResourceManager::DrawInWindow(int id, Scuare& clip, Vector& position, int scale, double angle, SDL_RendererFlip flip, SDL_Point* center)
{
	SDL_Rect src;
	SDL_Rect dest;

	src.x = clip.x;	src.y = clip.y; src.w = clip.w;	src.h = clip.h;	
	dest.x = position.x; dest.y = position.y; dest.w = clip.w * scale; dest.h =clip.h * scale;

	SDL_RenderCopyEx(_renderer, _textureVector[id], &src, &dest,angle,center,flip);
}

void ResourceManager::updateWindow()
{
	SDL_RenderPresent(_renderer);
}
/**/
void ResourceManager::changeAlpha(int id, int alpha)
{
	SDL_SetTextureAlphaMod(_textureVector[id], alpha);
}
/**/


void ResourceManager::clearWindow()
{
	SDL_RenderClear(_renderer);
}

ResourceManager::~ResourceManager()
{
	for (Uint32 i = 0; i < _textureVector.size(); i++)
	{
		SDL_DestroyTexture(_textureVector[i]);
	}

	_textureVector.clear();
	_idMap.clear();
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	_window = NULL;
	_renderer = NULL;
	
	_instance = NULL;

	SDL_Quit();
	IMG_Quit();
}
