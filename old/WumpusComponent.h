#pragma once
#include <string>
using namespace std;

class Wumpus;

class WumpusComponent
{
public:
	WumpusComponent();
	~WumpusComponent();

	virtual Wumpus* begin() = 0;
	virtual Wumpus* end() = 0;
	virtual Wumpus* next() = 0;
	virtual void addMonsterToPack(WumpusComponent* other) = 0;
	virtual string moveTo(int pos) = 0;
	virtual string attackPlayer() = 0;
	virtual string toString() = 0;
};

WumpusComponent::WumpusComponent()
{
}

WumpusComponent::~WumpusComponent()
{
}
