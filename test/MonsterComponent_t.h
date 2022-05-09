#pragma once

class Bat;

template <typename Self>
class MonsterComponent
{
public:
	MonsterComponent();
	~MonsterComponent();

	//virtual Monster* begin() = 0; innecesario porque MonsterPack lo hereda de vector< T >
	//virtual Monster* end() = 0; innecesario porque MonsterPack lo hereda de vector< T >
	//virtual Monster* next() = 0; innecesario porque MonsterPack lo hereda de vector< T >
	virtual string toString() = 0;

	template < typename T >
	void connect_to(T& other) {
		for (Bat& from : *static_cast<Self*>(this))
		{
			for (Bat& to : other)
			{
				from.out_push_back(to);
				to.in_push_back(from);
			}
		}
	}
};


template <typename Self>
MonsterComponent< Self >::MonsterComponent()
{
}

template <typename Self>
MonsterComponent< Self >::~MonsterComponent()
{
}

