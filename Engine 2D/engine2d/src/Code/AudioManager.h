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
			Descripción: Actualiza _firstFreeSlot.
		*/
		void updateFirrstFreeSlot();
		/*
			Descripcón: Añade un sonido al vector de sonidos.
			Entrada: La ruta del sonido.
			Salida: La posición del sonido en el vector.
		*/
		Uint32 addSound(const char* path);
	/*-----------------------------------*/
protected:
	AudioManager();
public:
	static AudioManager* getInstance();
	/*
		Descripción:Devuelve la posición del sonido en el vector.
		Entrada: La ruta del sonido.
		Salida: La posición del sonido en el vector.
	*/
	Uint32 getSoundId(const char* path);
	/*
		Descripción: Elimina un sonido en caso de que este no esté sonando.
		Entrada: La ruta del sonido, el canal del sonido.
	*/
	void removeSound(const char* path, int channel);
	/*
		Descripción: Devuelve el canal del sonido.
		Entrada: La posición del sonido en el vector.
		Salida: El número del canal que ocupa el sonido.
	*/
	Uint32 getChanelSound(Uint32 id);	
	/*
		Descripción: Reproduce un sonido en un cannal aleatorio y guarda el número del canal.
		Entrada: La posición del sonido en el vector, número de veces que se reproduce (por defecto 0).
	*/
	void playSound(Uint32 id,int loop = 0);
	/*
		Descripción: Detiene un canal que esté sonando.
		Entrada: Número del canal.
	*/
	void stopSound(Uint32 idChannel);
	/*
		Descripción: Vuelve a reproducir un canal que esté detenido.
		Entrada: Número del canal.
	*/
	void resumeSound(Uint32 idChannel);
	/*
		Descripción: Cambia el valor del volumen de un canal.
		Entrada: Número del canal, calor del volumen (máximo 128).
	*/
	void changeVolume(int idChannel, int volume);
	~AudioManager();
};

