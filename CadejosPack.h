#pragma once
#include <vector>
using namespace std;

#include "Cadejos.h"
#include "CadejosComponent.h"

class Cadejos;

class CadejosPack : public CadejosComponent
{
public:

	CadejosPack();
	~CadejosPack();

	unsigned int gId();
	Cadejos* begin() override;
	Cadejos* end() override;
	Cadejos* next() override;
	void addMonsterToPack(CadejosComponent *other) override;
	string moveTo(int pos) override;
    string attackPlayer() override;
	string toString() override;

private:
	static unsigned int idg;

	int id;
	vector< Cadejos > Cadejoses;
	vector<Cadejos*> children;
	int pos;
	Cadejos* cursor;
};

// Definición de variables static:
unsigned int CadejosPack::idg = 0;

CadejosPack::CadejosPack()
{
	this->id = CadejosPack::idg++;

		
	pos = 0;
	cursor = &Cadejoses[pos];
}

CadejosPack::~CadejosPack()
{
}

unsigned int CadejosPack::gId()
{
	return id;
}


Cadejos* CadejosPack::begin()
{
	pos = 0;
	cursor = &Cadejoses[pos];
	return cursor;
}

Cadejos* CadejosPack::end()
{
	return 0;
}

Cadejos* CadejosPack::next()
{
	if (pos < Cadejoses.size() - 1) {
		pos++;
		cursor = &Cadejoses[pos];
	}
	else cursor = 0;
	return cursor;
}

void CadejosPack::addMonsterToPack(CadejosComponent *other)
{
	auto w = static_cast<Cadejos *>(other);
	children.push_back(w);
}

string CadejosPack::moveTo(int pos)
{
    ostringstream salida;
    for (auto w : children)
        salida << w->moveTo(pos);
    return salida.str();
}

string CadejosPack::attackPlayer()
{
    ostringstream salida;
    for (auto w : children)
        return w->attackPlayer();
    return salida.str();
}

string CadejosPack::toString()
{
	ostringstream salida;
	salida << "Manada de Cadejos #" << id << endl;
	for (auto n : children)
		salida << n->toString();
	return salida.str();
}