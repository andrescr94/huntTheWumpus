#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "WumpusComponent.h"

class Wumpus : public WumpusComponent
{
public:
	Wumpus();
	~Wumpus();

	unsigned int gId();
	Wumpus *begin() override;
	Wumpus *end() override;
	Wumpus *next() override;
	void addMonsterToPack(WumpusComponent *other) override;
	string moveTo(int pos) override;
	string attackPlayer() override;
	string toString() override;

private:
	static unsigned int idg;

	unsigned int id;
	Wumpus *cursor;
	vector<Wumpus> in, out;
};

// Definición de variables static:
unsigned int Wumpus::idg = 0;

// Definición de métodos:
Wumpus::Wumpus()
{
	this->id = Wumpus::idg++;
	cursor = this;
}

Wumpus::~Wumpus()
{
}

unsigned int Wumpus::gId()
{
	return id;
}



Wumpus *Wumpus::begin()
{
	cursor = this;
	return cursor;
}

Wumpus *Wumpus::end()
{
	return 0;
}

Wumpus *Wumpus::next()
{
	cursor = 0;
	return cursor;
}

void Wumpus::addMonsterToPack(WumpusComponent *other)
{
	// auto w = static_cast<WumpusPack *>(other);
	other->addMonsterToPack(this);
}

string Wumpus::moveTo(int pos)
{
	ostringstream salida;
	salida << "Wumpus " << id << " se mueve a " << pos << endl;
	return salida.str();
}

string Wumpus::attackPlayer()
{
	ostringstream salida;
	salida << "Wumpus " << id << " ataca a jugador." << endl;
	return salida.str();
}

string Wumpus::toString()
{
	ostringstream salida;
	salida << "Wumpus #" << id << endl;
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