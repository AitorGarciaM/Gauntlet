#pragma once
#include "Core.h"

class Input
{
private:
	bool _salir;
	static Input* _instance;
	SDL_Event test_event;
	std::vector<bool> _keys; // Guarda el valor de las teclas.
	std::vector<bool> _keysFlagDown; // Guarda el valor de las teclas tipo flag que se pulsan.
	std::vector<bool> _keysFlagUp; // Guarda el valor de las teclas de tipo flag que se despulsan.
	SDL_Rect mousePos; // Guarda la posición del mouse.

	/*-------funciones-------*/
	
	/*-----------------------*/
protected:
	Input();
public:
	
	static Input* getInstance();

	/*
		Descripción: retorna si la tecla que le pasas está pulsada.
		Entrada: posición de la tecla en el vector keys.
		Salida: Devuelve el valor de la posición del vector.
	*/
	bool getKeyDown(int idKey);

	/*
		Descripción: retorna si la tecla que le pasas no está pulsada.
		Entrada: Posición de la tecla en el vector.
		Salida: El valor de la tecla en la posición del vector.
	*/
	bool getKeyUp(int idKey);

	/*
		Descripción: Devuelve si la tecla que le pasas está pulsada.
		Entrada: Posición de la tecla en el vector _keysFlagDown.
		Salida: El valor de la posición del vector.
	*/
	bool getKeyFlagDown(int idKey);

	/*
		Descripción: Devuelve si la tecla que le pasas está despulsada.
		Entrada: Posición de la tecla en el vector _keyFlagUp.
		Salida: El valor de la posición del vector.
	*/
	bool getKeyFlagUP(int idKey);

	/*
		Descripción: retorna la posición del mouse.
	*/
	SDL_Rect getMousePos();

	bool getExit();

	void update();
	
	~Input();
};

