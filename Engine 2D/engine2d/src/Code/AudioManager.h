#pragma once
#include "Core.h"
#include<SDL_mixer.h>
class AudioManager
{
private:
	static AudioManager* _instance;
	std::vector<Mix_Chunk*> _soundVector; // Guarda los sonidos cargados.
	std::vector<Uint32> _chanelsVector; // Guarda en que canal se encuentra un sonido.
	std::map<std::string, Uint32> _idMap;
	Uint32 _firstFreeSlot;

	/*-------------Functions-------------*/
		/*
			Descripci�n: Actualiza _firstFreeSlot.
		*/
		void updateFirrstFreeSlot();
		/*
			Descripc�n: A�ade un sonido al vector de sonidos.
			Entrada: La ruta del sonido.
			Salida: La posici�n del sonido en el vector.
		*/
		Uint32 addSound(const char* path);
	/*-----------------------------------*/
protected:
	AudioManager();
public:
	static AudioManager* getInstance();
	/*
		Descripci�n:Devuelve la posici�n del sonido en el vector.
		Entrada: La ruta del sonido.
		Salida: La posici�n del sonido en el vector.
	*/
	Uint32 getSoundId(const char* path);
	/*
		Descripci�n: Elimina un sonido en caso de que este no est� sonando.
		Entrada: La ruta del sonido, el canal del sonido.
	*/
	void removeSound(const char* path, int channel);
	/*
		Descripci�n: Devuelve el canal del sonido.
		Entrada: La posici�n del sonido en el vector.
		Salida: El n�mero del canal que ocupa el sonido.
	*/
	Uint32 getChanelSound(Uint32 id);	
	/*
		Descripci�n: Reproduce un sonido en un cannal aleatorio y guarda el n�mero del canal.
		Entrada: La posici�n del sonido en el vector, n�mero de veces que se reproduce (por defecto 0).
	*/
	void playSound(Uint32 id,int loop = 0);
	/*
		Descripci�n: Detiene un canal que est� sonando.
		Entrada: N�mero del canal.
	*/
	void stopSound(Uint32 idChannel);
	/*
		Descripci�n: Vuelve a reproducir un canal que est� detenido.
		Entrada: N�mero del canal.
	*/
	void resumeSound(Uint32 idChannel);
	/*
		Descripci�n: Cambia el valor del volumen de un canal.
		Entrada: N�mero del canal, calor del volumen (m�ximo 128).
	*/
	void changeVolume(int idChannel, int volume);
	~AudioManager();
};

