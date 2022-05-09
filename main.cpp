#include <iostream>
using namespace std;

#include "Neuron_p.h"
#include "NeuronLayer_p.h"

int main() {
	Neuron n1, n2;
	NeuronLayer nl1(3), nl2(3);

	n1.connect_to< Neuron >(n2);
	n1.connect_to< NeuronLayer>(nl1);
	nl2.connect_to< Neuron >(n2);
	nl1.connect_to< NeuronLayer>(nl2);

	cout << "**** INICIO ****" << endl;
	cout << n1.toString() << endl; // 0 in sal 1 2 3 4
	cout << n2.toString() << endl; // 1 in 0
	cout << nl1.toString() << endl;
	cout << nl2.toString() << endl;
	cout << "**** FIN ****" << endl;
	cin.ignore();
}

/*
0 in {} out {1,}
1 in {0,} out {}
2 in {} out {}
3 in {} out {}
4 in {} out {}
5 in {} out {}
6 in {} out {}
7 in {} out {}

capa 0

capa 1

**** INICIO ****
Neurona id: 0
ids entrantes: 

ids salientes: 
1,2,3,4,


Neurona id: 1
ids entrantes: 
0,5,6,7,
ids salientes: 



Capa neuronal id: 0
Neurona id: 2
ids entrantes: 
0,
ids salientes: 
5,6,7,

Neurona id: 3
ids entrantes: 
0,
ids salientes: 
5,6,7,

Neurona id: 4
ids entrantes: 
0,
ids salientes: 
5,6,7,


Capa neuronal id: 0
Neurona id: 5
ids entrantes: 
2,3,4,
ids salientes: 
1,

Neurona id: 6
ids entrantes: 
2,3,4,
ids salientes: 
1,

Neurona id: 7
ids entrantes: 
2,3,4,
ids salientes: 
1,


**** FIN ****
*/