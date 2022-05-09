#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "MonsterComponent_t.h"

class Bat : public MonsterComponent< Bat >
{
public:
	Bat();
	~Bat();

	unsigned int gId();
	void out_push_back(Bat& other);
	void in_push_back(Bat& other);
	Bat* begin() { return this; };
	Bat* end() { return this + 1; };
	string toString();

private:
	static unsigned int idg;

	unsigned int id;
	vector<Bat> in, out;
};

// Definición de variables static:
unsigned int Bat::idg = 0;

// Definición de métodos:
Bat::Bat()
{
	this->id = Bat::idg++;
}

Bat::~Bat()
{
}

unsigned int Bat::gId()
{
	return id;
}

void Bat::out_push_back(Bat& other)
{
	out.push_back(other);
}

void Bat::in_push_back(Bat& other)
{
	in.push_back(other);
}

string Bat::toString()
{
	ostringstream salida;
	salida << "Bata id: " << id << endl;
	salida << "ids entrantes: " << endl;
	for (auto n : in)
		salida << n.gId() << ",";
	salida << endl;
	salida << "ids salientes: " << endl;
	for (auto n : out)
		salida << n.gId() << ",";
	salida << endl; salida << endl;
	return salida.str();
}