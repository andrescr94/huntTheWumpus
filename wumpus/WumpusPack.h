#pragma once
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "Wumpus.h"
#include "WumpusComponent.h"

class WumpusPack : public WumpusComponent
{
public:
    // Construye una WumpusPack con "count" Wumpuses.
    WumpusPack(int count);
    ~WumpusPack();
    unsigned int gId();
    Wumpus *begin() override;
    Wumpus *end() override;
    Wumpus *next() override;
    string moveTo(int pos) override;
    string attackPlayer() override;
    void addMonster(Wumpus *other);
    void connect_to(WumpusComponent *other) override;
    string toString();

private:
    static unsigned int idg;

    int id;
    vector<Wumpus> wumpuses;
    int pos;
    Wumpus *cursor;
};

// Definición de variables static:
unsigned int WumpusPack::idg = 0;

WumpusPack::WumpusPack(int count)
{
    this->id = WumpusPack::idg++;
    while (count-- > 0)
        wumpuses.emplace_back(Wumpus{});
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

Wumpus *WumpusPack::begin()
{
    pos = 0;
    cursor = &wumpuses[pos];
    return cursor;
}

Wumpus *WumpusPack::end()
{
    return 0;
}

Wumpus *WumpusPack::next()
{
    if (pos < wumpuses.size() - 1)
    {
        pos++;
        cursor = &wumpuses[pos];
    }
    else
        cursor = 0;
    return cursor;
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

void WumpusPack::addMonster(Wumpus *other)
{
    this->wumpuses.emplace_back(*other);
}

void WumpusPack::connect_to(WumpusComponent *other)
{
    Wumpus *from = this->begin();
    while (from != 0)
    {
        Wumpus *to = other->begin();
        while (to != 0)
        {
            from->out_push_back(*to);
            to->in_push_back(*from);
            to = other->next();
        }
        from = this->next();
    }
}

string WumpusPack::toString()
{
    ostringstream salida;
    salida << "Manada de Wumpus id: " << id << endl;
    for (auto n : wumpuses)
        salida << n.toString();
    return salida.str();
}