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
	SDL_Rect mousePos; // Guarda la posici�n del mouse.

	/*-------funciones-------*/
	
	/*-----------------------*/
protected:
	Input();
public:
	
	static Input* getInstance();

	/*
		Descripci�n: retorna si la tecla que le pasas est� pulsada.
		Entrada: posici�n de la tecla en el vector keys.
		Salida: Devuelve el valor de la posici�n del vector.
	*/
	bool getKeyDown(int idKey);

	/*
		Descripci�n: retorna si la tecla que le pasas no est� pulsada.
		Entrada: Posici�n de la tecla en el vector.
		Salida: El valor de la tecla en la posici�n del vector.
	*/
	bool getKeyUp(int idKey);

	/*
		Descripci�n: Devuelve si la tecla que le pasas est� pulsada.
		Entrada: Posici�n de la tecla en el vector _keysFlagDown.
		Salida: El valor de la posici�n del vector.
	*/
	bool getKeyFlagDown(int idKey);

	/*
		Descripci�n: Devuelve si la tecla que le pasas est� despulsada.
		Entrada: Posici�n de la tecla en el vector _keyFlagUp.
		Salida: El valor de la posici�n del vector.
	*/
	bool getKeyFlagUP(int idKey);

	/*
		Descripci�n: retorna la posici�n del mouse.
	*/
	SDL_Rect getMousePos();

	bool getExit();

	void update();
	
	~Input();
};

