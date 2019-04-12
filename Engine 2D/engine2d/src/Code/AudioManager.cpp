#include "AudioManager.h"

AudioManager* AudioManager::_instance = NULL;

void AudioManager::updateFirrstFreeSlot()
{
	for (Uint32 i = 0; i < _soundVector.size(); i++)
	{
		if (_soundVector[i] == NULL)
		{
			_firstFreeSlot = i;
		}
	}
}

Uint32 AudioManager::addSound(const char * path)
{
	Mix_Chunk* loadedSound = Mix_LoadWAV(path);
	if (_firstFreeSlot < _soundVector.size())
	{
		Uint32 id = _firstFreeSlot;
		_firstFreeSlot = _soundVector.size();
		_soundVector[id] = loadedSound;
		return id;
	}
	else
	{
		_soundVector.push_back(loadedSound);
		_firstFreeSlot = _soundVector.size();
		return _firstFreeSlot - 1;
	}
}

AudioManager::AudioManager()
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(128);
}


AudioManager * AudioManager::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new AudioManager();
	}
	
	return _instance;
}

Uint32 AudioManager::getSoundId(const char * path)
{
	std::map<std::string, Uint32>::iterator it = _idMap.find(path);
	if (it == _idMap.end())
	{
		Uint32 id = addSound(path);
		_idMap[path] = id;
	}

	return _idMap[path];
}

void AudioManager::removeSound(const char * path, int channel)
{
	std::map<std::string, Uint32>::iterator it = _idMap.find(path);

	if(it != _idMap.end() && (Mix_Playing(channel) == 0))
	{
		
		Mix_FreeChunk(_soundVector[it->second]);
		_soundVector[it->second] = NULL;
		_idMap.erase(path);
		updateFirrstFreeSlot();
	}
}

Uint32 AudioManager::getChanelSound(Uint32 id)
{
	return _chanelsVector[id];
}

void AudioManager::playSound(Uint32 id,int loop)
{
	Mix_PlayChannel(-1, _soundVector[id], loop);
}

void AudioManager::stopSound(Uint32 idchannel)
{
	Mix_Pause(idchannel);
}

void AudioManager::resumeSound(Uint32 idChannel)
{
	Mix_Resume(idChannel);
}

void AudioManager::changeVolume(int idChannel, int volume)
{
	if (volume > 128) 
	{
		volume = 128;
	}
	else if (volume < 0)
	{
		volume = 0;
	}

	Mix_Volume(idChannel, volume);
}

AudioManager::~AudioManager()
{
	for (Uint32 i = 0; i < _soundVector.size(); i++)
	{
		Mix_FreeChunk(_soundVector[i]);
	}

	_soundVector.clear();
	_idMap.clear();

	Mix_CloseAudio();
	Mix_Quit();
}
