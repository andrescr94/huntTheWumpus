#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "Neurons.h"

class Neuron : public Neurons< Neuron >
{
public:
	Neuron();
	~Neuron();

	unsigned int gId();
	void out_push_back(Neuron& other);
	void in_push_back(Neuron& other);
	Neuron* begin() { return this; };
	Neuron* end() { return this + 1; };
	string toString();

private:
	static unsigned int idg;

	unsigned int id;
	vector<Neuron> in, out;
};

// Definición de variables static:
unsigned int Neuron::idg = 0;

// Definición de métodos:
Neuron::Neuron()
{
	this->id = Neuron::idg++;
}

Neuron::~Neuron()
{
}

unsigned int Neuron::gId()
{
	return id;
}

void Neuron::out_push_back(Neuron& other)
{
	out.push_back(other);
}

void Neuron::in_push_back(Neuron& other)
{
	in.push_back(other);
}

string Neuron::toString()
{
	ostringstream salida;
	salida << "Neurona id: " << id << endl;
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