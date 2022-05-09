#pragma once
#include <vector>
using namespace std;

#include "Wumpus.h"
#include "WumpusComponent.h"

class Wumpus;

class WumpusPack : public WumpusComponent
{
public:

	WumpusPack();
	~WumpusPack();

	unsigned int gId();
	Wumpus* begin() override;
	Wumpus* end() override;
	Wumpus* next() override;
	void addMonsterToPack(WumpusComponent *other) override;
	string moveTo(int pos) override;
    string attackPlayer() override;
	string toString() override;

private:
	static unsigned int idg;

	int id;
	vector< Wumpus > wumpuses;
	vector<Wumpus*> children;
	int pos;
	Wumpus* cursor;
};

// Definición de variables static:
unsigned int WumpusPack::idg = 0;

WumpusPack::WumpusPack()
{
	this->id = WumpusPack::idg++;

		
	pos = 0;
	cursor = &wumpuses[pos];
}

WumpusPack::~WumpusPack()
{
}

unsigned int WumpusPack::gId()
{
	return id;
}


Wumpus* WumpusPack::begin()
{
	pos = 0;
	cursor = &wumpuses[pos];
	return cursor;
}

Wumpus* WumpusPack::end()
{
	return 0;
}

Wumpus* WumpusPack::next()
{
	if (pos < wumpuses.size() - 1) {
		pos++;
		cursor = &wumpuses[pos];
	}
	else cursor = 0;
	return cursor;
}

void WumpusPack::addMonsterToPack(WumpusComponent *other)
{
	auto w = static_cast<Wumpus *>(other);
	children.push_back(w);
}

string WumpusPack::moveTo(int pos)
{
    ostringstream salida;
    for (auto w : wumpuses)
        salida << w.moveTo(pos);
    return salida.str();
}

string WumpusPack::attackPlayer()
{
    ostringstream salida;
    for (auto w : wumpuses)
        return w.attackPlayer();
    return salida.str();
}

string WumpusPack::toString()
{
	ostringstream salida;
	salida << "Manada de wumpus #" << id << endl;
	for (auto n : children)
		salida << n->toString();
	return salida.str();
}