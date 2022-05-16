#pragma once
#include <vector>
using namespace std;

#include "Wumpus.h"
#include "MonsterPack.h"

class Wumpus;

class WumpusPack : public MonsterPack
{
public:

	WumpusPack();
	~WumpusPack();

	string toString() override;
};


WumpusPack::WumpusPack(){}

WumpusPack::~WumpusPack(){}

string WumpusPack::toString()
{
	ostringstream salida;
	salida << "Manada de wumpus #" << gId() << endl;
	Wumpus *w = static_cast<Wumpus*>(this->begin());
    while (w != 0)
    {
        salida << w->toString();
        w = static_cast<Wumpus*>(this->next());
    }
	return salida.str();
}