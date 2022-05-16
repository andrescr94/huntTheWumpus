#pragma once
#include "MonsterComponent.h"
#include <iostream>
class MonsterMemory : public MonsterComponent
{
public:
    MonsterMemory(MonsterComponent &other) : monsterComponent(other) {}
    // InvisibleMonster(MonsterComponent &MonsterComponent);
    Monster *begin() override;
    Monster *end() override;
    Monster *next() override;
    void addMonsterToPack(MonsterComponent *other) override;
    string moveTo(int pos) override;
    string attackPlayer() override;
    string toString() override;

private:
    MonsterComponent &monsterComponent;
};
// InvisibleMonster::InvisibleMonster(MonsterComponent &MonsterComponent) : monsterComponent{monsterComponent}
// {
// }

Monster *MonsterMemory::begin()
{
    this->monsterComponent.begin();
}
Monster *MonsterMemory::end()
{
    this->monsterComponent.end();
}
Monster *MonsterMemory::next()
{
    this->monsterComponent.next();
}
void MonsterMemory::addMonsterToPack(MonsterComponent *other)
{
    this->monsterComponent.addMonsterToPack(other);
}
string MonsterMemory::moveTo(int pos)
{
    this->monsterComponent.moveTo(pos);
}
string MonsterMemory::attackPlayer()
{
    this->monsterComponent.attackPlayer();
}
string MonsterMemory::toString()
{
    ostringstream salida;
    salida << this->monsterComponent.toString() << "tiene memoria " << endl;
    return salida.str();
}