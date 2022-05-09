#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "Monster.h"

class Wolf : public Monster
{
public:
	Wolf();
	~Wolf();

	string attackPlayer() override;
	string toString() override;
};

// Definición de métodos:
Wolf::Wolf(){}

Wolf::~Wolf(){}

string Wolf::attackPlayer()
{
	ostringstream salida;
	salida << "Lobo #" << gId() << " ataca a jugador." << endl;
	return salida.str();
}

string Wolf::toString()
{
	ostringstream salida;
	salida << "Wolf #" << gId() << endl;
	return salida.str();
}