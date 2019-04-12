#pragma once
#include "Entity.h"
class Pawn : public Entity
{
protected:
	int _vida;
	bool _vivo;
	int _attack;
public:
	void die();
	void damage(int damage);
	Pawn();
	~Pawn();
};

