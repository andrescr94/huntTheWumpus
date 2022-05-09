#pragma once
#include <vector>
using namespace std;

#include "Wolf.h"
#include "MonsterPack.h"

class Wolf;

class WolfPack : public MonsterPack
{
public:
    WolfPack();
    ~WolfPack();

    string toString() override;
};

WolfPack::WolfPack(){}

WolfPack::~WolfPack(){}

string WolfPack::toString()
{
    ostringstream salida;
    salida << "Manada de lobos #" << this->gId() << endl;
    Wolf *w = static_cast<Wolf*>(this->begin());
    while (w != 0)
    {
        salida << w->toString();
        w = static_cast<Wolf*>(this->next());
    }

    return salida.str();
}