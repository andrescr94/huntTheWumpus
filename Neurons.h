#pragma once

class Neuron;

template <typename Self>
class Neurons
{
public:
	Neurons();
	~Neurons();

	//virtual Neuron* begin() = 0; innecesario porque NeuronLayer lo hereda de vector< T >
	//virtual Neuron* end() = 0; innecesario porque NeuronLayer lo hereda de vector< T >
	//virtual Neuron* next() = 0; innecesario porque NeuronLayer lo hereda de vector< T >
	virtual string toString() = 0;

	template < typename T >
	void connect_to(T& other) {
		for (Neuron& from : *static_cast<Self*>(this))
		{
			for (Neuron& to : other)
			{
				from.out_push_back(to);
				to.in_push_back(from);
			}
		}
	}
};


template <typename Self>
Neurons< Self >::Neurons()
{
}

template <typename Self>
Neurons< Self >::~Neurons()
{
}