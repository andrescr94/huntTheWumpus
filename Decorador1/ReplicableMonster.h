#pragma once
#include "MonsterComponent.h"
#include <iostream>
class ReplicableMonster : public MonsterComponent
{
public:
    ReplicableMonster(MonsterComponent &other) : monsterComponent(other) {}
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

Monster *ReplicableMonster::begin()
{
    this->monsterComponent.begin();
}
Monster *ReplicableMonster::end()
{
    this->monsterComponent.end();
}
Monster *ReplicableMonster::next()
{
    this->monsterComponent.next();
}
void ReplicableMonster::addMonsterToPack(MonsterComponent *other)
{
    this->monsterComponent.addMonsterToPack(other);
}
string ReplicableMonster::moveTo(int pos)
{
    this->monsterComponent.moveTo(pos);
}
string ReplicableMonster::attackPlayer()
{
    this->monsterComponent.attackPlayer();
}
string ReplicableMonster::toString()
{
    ostringstream salida;
    salida << this->monsterComponent.toString() << "es replicable " << endl;
    return salida.str();
}