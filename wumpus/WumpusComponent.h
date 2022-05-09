#pragma once
#include <string>
class Wumpus;

class WumpusComponent
{
public:
	WumpusComponent();
	~WumpusComponent();

	virtual Wumpus* begin() = 0;
	virtual Wumpus* end() = 0; 
	virtual Wumpus* next() = 0; 
	virtual string moveTo(int pos) = 0;
	virtual string attackPlayer() = 0;
	virtual string toString() = 0;
	virtual void connect_to(WumpusComponent* other) = 0;
};


WumpusComponent::WumpusComponent()
{
}

WumpusComponent::~WumpusComponent()
{
}

// Wumpus
// Cadejos

// controlar ciclo de juego
// cuando el juego ha terminado
// declarar un ganador del juego
// crear monstruos
// formar manadas con otros monstruos
// se puede agregar o quitar un monstruo

// moverse
// atacar jugador
// que clase soy

// otros monstuos
