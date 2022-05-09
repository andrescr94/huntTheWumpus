#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "CadejosComponent.h"

class Cadejos : public CadejosComponent
{
public:
	Cadejos();
	~Cadejos();

	unsigned int gId();
	Cadejos *begin() override;
	Cadejos *end() override;
	Cadejos *next() override;
	void addMonsterToPack(CadejosComponent *other) override;
	string moveTo(int pos) override;
	string attackPlayer() override;
	string toString() override;

private:
	static unsigned int idg;

	unsigned int id;
	Cadejos *cursor;
	vector<Cadejos> in, out;
};

// Definición de variables static:
unsigned int Cadejos::idg = 0;

// Definición de métodos:
Cadejos::Cadejos()
{
	this->id = Cadejos::idg++;
	cursor = this;
}

Cadejos::~Cadejos()
{
}

unsigned int Cadejos::gId()
{
	return id;
}



Cadejos *Cadejos::begin()
{
	cursor = this;
	return cursor;
}

Cadejos *Cadejos::end()
{
	return 0;
}

Cadejos *Cadejos::next()
{
	cursor = 0;
	return cursor;
}

void Cadejos::addMonsterToPack(CadejosComponent *other)
{
	// auto w = static_cast<CadejosPack *>(other);
	other->addMonsterToPack(this);
}

string Cadejos::moveTo(int pos)
{
	ostringstream salida;
	salida << "Cadejos " << id << " se mueve a " << pos << endl;
	return salida.str();
}

string Cadejos::attackPlayer()
{
	ostringstream salida;
	salida << "Cadejos " << id << " ataca a jugador." << endl;
	return salida.str();
}

string Cadejos::toString()
{
	ostringstream salida;
	salida << "Cadejos #" << id << endl;
	// salida << "ids entrantes: " << endl;
	// for (auto n : in)
	// 	salida << n.gId() << ",";
	// salida << endl;
	// salida << "ids salientes: " << endl;
	// for (auto n : out)
	// 	salida << n.gId() << ",";
	// salida << endl; salida << endl;
	return salida.str();
}