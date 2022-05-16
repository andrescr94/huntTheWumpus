#pragma once
#include <vector>
using namespace std;

#include "Cadejos.h"
#include "MonsterPack.h"

class Cadejos;

class CadejosPack : public MonsterPack
{
public:

	CadejosPack();
	~CadejosPack();

	string toString() override;
};

CadejosPack::CadejosPack(){}

CadejosPack::~CadejosPack(){}

string CadejosPack::toString()
{
	ostringstream salida;
	salida << "Manada de Cadejos #" << gId() << endl;
	Cadejos *c = static_cast<Cadejos*>(this->begin());
    while (c != 0)
    {
        salida << c->toString();
        c = static_cast<Cadejos*>(this->next());
    }
	return salida.str();
}