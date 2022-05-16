#pragma once
#include "MonsterComponent.h"
#include <iostream>
class InvisibleMonster : public MonsterComponent
{
public:
    InvisibleMonster(MonsterComponent &other) : monsterComponent(other) {}
    
    Monster *begin() override;
    Monster *end() override;
    Monster* next() override;
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

Monster* InvisibleMonster::begin()
{
    this->monsterComponent.begin();
}
Monster* InvisibleMonster::end()
{
    this->monsterComponent.end();
}
Monster* InvisibleMonster::next()
{
    this->monsterComponent.next();
}
void InvisibleMonster::addMonsterToPack(MonsterComponent*other)
{
    this->monsterComponent.addMonsterToPack(other);
}
string InvisibleMonster::moveTo(int pos)
{
    this->monsterComponent.moveTo(pos);
}
string InvisibleMonster::attackPlayer()
{
    this->monsterComponent.attackPlayer();
}
string InvisibleMonster::toString()
{

    ostringstream salida;
    salida << this->monsterComponent.toString() << "es invisible " << endl;
    return salida.str();
}