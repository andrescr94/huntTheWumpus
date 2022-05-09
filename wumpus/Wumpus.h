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
	void out_push_back(Wumpus& other);
	void in_push_back(Wumpus& other);
	Wumpus* begin() override;
	Wumpus* end() override;
	Wumpus* next() override;
	string moveTo(int pos) override;
	string attackPlayer() override;
	void addToPack(int newPack);
	void connect_to(WumpusComponent* other) override;
	string toString() override;

private:
	static unsigned int idg;

	unsigned int id;
	vector<Wumpus> in, out;
	int pack;
	Wumpus* cursor;
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

void Wumpus::addToPack(int newPack)
{	
	this->pack = newPack;
}

void Wumpus::out_push_back(Wumpus& other)
{
	out.push_back(other);
}

void Wumpus::in_push_back(Wumpus& other)
{
	in.push_back(other);
}

void Wumpus::connect_to(WumpusComponent* other)
{
	Wumpus* from = this->begin();
	while (from != 0) {
		Wumpus* to = other->begin();
		while (to != 0) {
			from->out_push_back(*to);
			to->in_push_back(*from);
			to = other->next();
		}
		from = this->next();
	}
}

string Wumpus::toString()
{
	ostringstream salida;
	salida << "Wumpus id: " << id << endl;
	salida << "Soy parte de manada: " << pack << endl; //pack->gId()
	// for (auto n : packs)
	// 	salida << n.gId() << ",";
	// salida << endl;
	return salida.str();
}