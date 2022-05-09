#pragma once
#include <string>
using namespace std;

class Cadejos;

class CadejosComponent
{
public:
	CadejosComponent();
	~CadejosComponent();

	virtual Cadejos* begin() = 0;
	virtual Cadejos* end() = 0;
	virtual Cadejos* next() = 0;
	virtual void addMonsterToPack(CadejosComponent* other) = 0;
	virtual string moveTo(int pos) = 0;
	virtual string attackPlayer() = 0;
	virtual string toString() = 0;
};

CadejosComponent::CadejosComponent()
{
}

CadejosComponent::~CadejosComponent()
{
}
