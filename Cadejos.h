#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "Monster.h"

class Cadejos : public Monster
{
public:
	Cadejos();
	~Cadejos();

	string attackPlayer() override;
	string toString() override;
};


// Definición de métodos:
Cadejos::Cadejos(){}

Cadejos::~Cadejos(){}


string Cadejos::attackPlayer()
{
	ostringstream salida;
	salida << "Cadejos # " << gId() << " ataca a jugador." << endl;
	return salida.str();
}

string Cadejos::toString()
{
	ostringstream salida;
	salida << "Cadejos #" << gId() << endl;
	return salida.str();
}