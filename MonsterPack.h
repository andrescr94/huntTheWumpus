#pragma once
#include <vector>
using namespace std;

#include "Monster.h"
#include "MonsterComponent.h"

class Monster;

class MonsterPack : public MonsterComponent
{
public:

	MonsterPack();
	~MonsterPack();

	unsigned int gId();
	Monster* begin() override;
	Monster* end() override;
	Monster* next() override;
	void addMonsterToPack(MonsterComponent *other) override;
	string moveTo(int pos) override;
    string attackPlayer() override;
	virtual string toString() = 0;

private:
	static unsigned int idg;

	int id;
	vector< Monster > Monsteres;
	vector<Monster*> children;
	int pos;
	Monster* cursor;
};

// Definición de variables static:
unsigned int MonsterPack::idg = 0;

MonsterPack::MonsterPack()
{
	this->id = MonsterPack::idg++;

		
	pos = 0;
	cursor = nullptr;
}

MonsterPack::~MonsterPack()
{
}

unsigned int MonsterPack::gId()
{
	return id;
}


Monster* MonsterPack::begin()
{
	pos = 0;
	cursor = children[pos];
	return cursor;
}

Monster* MonsterPack::end()
{
	return 0;
}

Monster* MonsterPack::next()
{
	if (pos < children.size() - 1) {
		pos++;
		cursor = children[pos];
	}
	else cursor = 0;
	return cursor;
}

void MonsterPack::addMonsterToPack(MonsterComponent *other)
{
	auto w = static_cast<Monster *>(other);
	children.push_back(w);
}

string MonsterPack::moveTo(int pos)
{
    ostringstream salida;
    for (auto w : children)
        salida << w->moveTo(pos);
    return salida.str();
}

string MonsterPack::attackPlayer()
{
    ostringstream salida;
    for (auto w : children)
        return w->attackPlayer();
    return salida.str();
}

string MonsterPack::toString()
{
	ostringstream salida;
	salida << "Manada de monstruos #" << id << endl;
	for (auto n : children)
		salida << n->toString();
	return salida.str();
}