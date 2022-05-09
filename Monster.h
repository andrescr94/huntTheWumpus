#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "MonsterComponent.h"

class Monster : public MonsterComponent
{
public:
	Monster();
	~Monster();

	unsigned int gId();
	Monster *begin() override;
	Monster *end() override;
	Monster *next() override;
	void addMonsterToPack(MonsterComponent *other) override;
	string moveTo(int pos) override;
	virtual string attackPlayer() = 0;
	virtual string toString() = 0;

private:
	static unsigned int idg;

	unsigned int id;
	Monster *cursor;
	vector<Monster> in, out;
};

// Definición de variables static:
unsigned int Monster::idg = 0;

// Definición de métodos:
Monster::Monster()
{
	this->id = Monster::idg++;
	cursor = this;
}

Monster::~Monster()
{
}

unsigned int Monster::gId()
{
	return id;
}



Monster *Monster::begin()
{
	cursor = this;
	return cursor;
}

Monster *Monster::end()
{
	return 0;
}

Monster *Monster::next()
{
	cursor = 0;
	return cursor;
}

void Monster::addMonsterToPack(MonsterComponent *other)
{
	// auto w = static_cast<MonsterPack *>(other);
	other->addMonsterToPack(this);
}

string Monster::moveTo(int pos)
{
	ostringstream salida;
	salida << "Monster " << id << " se mueve a " << pos << endl;
	return salida.str();
}


