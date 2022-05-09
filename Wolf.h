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

	// unsigned int gId();
	// Wumpus *begin() override;
	// Wumpus *end() override;
	// Wumpus *next() override;
	// void addMonsterToPack(WumpusComponent *other) override;
	// string moveTo(int pos) override;
	string attackPlayer() override;
	string toString() override;

};



// Definición de métodos:
Wolf::Wolf()
{

}

Wolf::~Wolf()
{
}

string Wolf::attackPlayer()
{
	ostringstream salida;
	salida << "Lobo " << gId() << " ataca a jugador." << endl;
	return salida.str();
}

string Wolf::toString()
{
	ostringstream salida;
	salida << "Wolf #" << gId() << endl;
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