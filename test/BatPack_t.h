#pragma once
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "Bat_t.h"
#include "MonsterComponent_t.h"

// Este uso de la herencia no es muy apropiado porque una BatPack NO
// es un ejemplo de vector< Bat >, es decir, NO es un vector lo que implica
// que se heredan muchos métodos que no tienen sentido para un BatPack.
class BatPack : public vector<Bat>, public MonsterComponent<BatPack>
{
public:
	// Construye una BatPack con "count" Batas.
	BatPack();
	~BatPack();

	string toString();

private:
	static unsigned int idg;

	int id;
};

// Definición de variables static:
unsigned int BatPack::idg = 0;

BatPack::BatPack()
{
	this->id = BatPack::idg++;

}

BatPack::~BatPack()
{
}

string BatPack::toString()
{
	ostringstream salida;
	salida << "Capa Batal id: " << id << endl;
	for (auto n : *this)
		salida << n.toString();
	return salida.str();
}