#pragma once
#include "Core.h"
#include<SDL_image.h>

class ResourceManager
{
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	static ResourceManager* _instance;
	std::map<std::string, Uint32> _idMap;
	std::vector<SDL_Texture*> _textureVector;
	Uint32 _firstFreeSlot;

	

	/*-------------------funciones-------------------*/
		/*
		 * Descripcion: Añade texturas al Vector _textureVector.
		 * Entrada: Ruta del archivo.
		 * Salida: id de la textura.
		*/
		Uint32 addTexture(const char* path);

		/*
		 * Descripcion: Busca la primera posición nula del vector _textureVector.
		 * Entrada: nada.
		 * Salida: La primera posición nula del vector _textureVector.
		*/
		void updateFirstFreeSlot();
	/*-----------------------------------------------*/

protected:
	ResourceManager();

public:
	static ResourceManager* getInstance();

	/*-------------------Resource Magement-------------------*/
	/*
	 * Descripcion: debuelve la id de la textura .
	 * Entrada: Ruta del archivo.
	 * Salida: id de la textura.
	*/
	 Uint32 getTextureID(const char* path);

	/*
	 * Descripcion: Eliminar textura de la RAM.
	 * Entrada: Ruta del archivo.
	 * Salida: Nada.
	*/
	void removeTexture(const char* path);

	/*
	 * Descripcion: Debueve un puntero de la imagen.
	 * Entrada: Posición de la imagen en el vector _textureVector.
	 * Salida: Puntero de la textura.
	*/
	SDL_Texture* getTextureBYId(Uint32 id);
	/*-------------------------------------------------------*/

	/*-------------------Video Management-------------------*/
	/*
	 * Descripcion: Dibuja una imagen por pantalla.
	 * Entrada: posición de la imagen en el vector, las medidas de la imagen, la posición de la imagen en pantalla, la escala de la imagen, el angulo de dibujado con la imagen, maskara de bits para girar la imagen, punto central de la imagen.
	 * Salida: Nada.
	*/
	void DrawInWindow(int id, Scuare& clip, Vector& position, int scale = 1, double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Point* center = NULL);

	/*
	 * Descripcion: Actualiza la pantalla.
	 * Entrada: Ruta del archivo.
	 * Salida: Nada.
	*/
	void updateWindow();
	/*
	 * Descripcion: Cambia el alpha de una textura.
	 * Entrada: Ruta del archivo.
	 * Salida: id de la textura.
	*/
	void changeAlpha(int id,int alpha);

	void clearWindow();
	/*------------------------------------------------------*/

	~ResourceManager();
};

