#pragma once
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "Neuron_p.h"
#include "Neurons.h"

// Este uso de la herencia no es muy apropiado porque una NeuronLayer NO 
// es un ejemplo de vector< Neuron >, es decir, NO es un vector lo que implica
// que se heredan muchos métodos que no tienen sentido para un NeuronLayer.
class NeuronLayer : public vector < Neuron >, public Neurons< NeuronLayer >
{
public:
	// Construye una NeuronLayer con "count" neuronas.
	NeuronLayer(int count);
	~NeuronLayer();

	string toString();
private:
	static unsigned int idg;
	int id;
};

// Definición de variables static:
unsigned int NeuronLayer::idg = 0;

NeuronLayer::NeuronLayer(int count)
{
	this->id = NeuronLayer::idg++;
	while (count-- > 0)
		emplace_back(Neuron{});
}

NeuronLayer::~NeuronLayer()
{
}

string NeuronLayer::toString()
{
	ostringstream salida;
	salida << "Capa neuronal id: " << id << endl;
	for (auto n : *this)
		salida << n.toString();
	return salida.str();
}