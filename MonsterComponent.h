#pragma once
#include <string>
using namespace std;

class Monster;

class MonsterComponent
{
public:
	MonsterComponent();
	~MonsterComponent();

	virtual Monster* begin() = 0;
	virtual Monster* end() = 0;
	virtual Monster* next() = 0;
	virtual void addMonsterToPack(MonsterComponent* other) = 0;
	virtual string moveTo(int pos) = 0;
	virtual string attackPlayer() = 0;
	virtual string toString() = 0;
};

MonsterComponent::MonsterComponent()
{
}

MonsterComponent::~MonsterComponent()
{
}
