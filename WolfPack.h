#pragma once
#include <vector>
using namespace std;

#include "Wolf.h"
#include "MonsterComponent.h"

class Wolf;

class WolfPack : public MonsterComponent
{
public:

	WolfPack();
	~WolfPack();

	unsigned int gId();
	Wolf* begin() override;
	Wolf* end() override;
	Wolf* next() override;
	void addMonsterToPack(MonsterComponent *other) override;
	string moveTo(int pos) override;
    string attackPlayer() override;
	string toString() override;

private:
	static unsigned int idg;

	int id;
	vector< Wolf > Wolfes;
	vector<Wolf*> children;
	int pos;
	Wolf* cursor;
};

// Definición de variables static:
unsigned int WolfPack::idg = 0;

WolfPack::WolfPack()
{
	this->id = WolfPack::idg++;

		
	pos = 0;
	cursor = &Wolfes[pos];
}

WolfPack::~WolfPack()
{
}

unsigned int WolfPack::gId()
{
	return id;
}


Wolf* WolfPack::begin()
{
	pos = 0;
	cursor = &Wolfes[pos];
	return cursor;
}

Wolf* WolfPack::end()
{
	return 0;
}

Wolf* WolfPack::next()
{
	if (pos < Wolfes.size() - 1) {
		pos++;
		cursor = &Wolfes[pos];
	}
	else cursor = 0;
	return cursor;
}

void WolfPack::addMonsterToPack(MonsterComponent *other)
{
	auto w = static_cast<Wolf *>(other);
	children.push_back(w);
}

string WolfPack::moveTo(int pos)
{
    ostringstream salida;
    for (auto w : children)
        salida << w->moveTo(pos);
    return salida.str();
}

string WolfPack::attackPlayer()
{
    ostringstream salida;
    for (auto w : children)
        return w->attackPlayer();
    return salida.str();
}

string WolfPack::toString()
{
	ostringstream salida;
	salida << "Manada de Wolf #" << id << endl;
	for (auto n : children)
		salida << n->toString();
	return salida.str();
}