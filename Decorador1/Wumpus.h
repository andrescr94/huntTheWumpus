#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "Monster.h"

class Wumpus : public Monster
{
public:
	Wumpus();
	~Wumpus();

	string attackPlayer() override;
	string toString() override;
};

// Definición de métodos:
Wumpus::Wumpus() {}

Wumpus::~Wumpus() {}

string Wumpus::attackPlayer()
{
	ostringstream salida;
	salida << "Wumpus #" << gId() << " ataca a jugador." << endl;
	return salida.str();
}

string Wumpus::toString()
{
	ostringstream salida;
	salida << "Wumpus #" << gId() << endl;
	return salida.str();
}