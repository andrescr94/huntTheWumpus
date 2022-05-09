#include <iostream>
using namespace std;


#include "Wumpus.h"
#include "WumpusPack.h"


int main() 
{
    cout << 1.0;
    Wumpus w0, w1, w2;
    cout << 2.0;
    WumpusPack wp0, wp1;
    
    // // Cadejos c0, c1, c2;    
    // // CadejosPack cp0, cp1;

    w0.addMonsterToPack(&wp0);
    w1.addMonsterToPack(&wp0);
    wp1.addMonsterToPack(&w2);

    // cp0.add(&c0);
    // cp0.add(&c1);
    // c2.add(&cp1);


    // doesn't work
    // w0.add(&c0);
    // wp0.add(&c1);
    // c1.add(&w0);
    // cp1.add(&w1);

    cout << "**** INICIO ****" << endl;
	cout << w0.toString() << endl;
	cout << w1.toString() << endl;
    cout << w2.toString() << endl;
    cout << wp0.toString() << endl;
	cout << wp1.toString() << endl;
    cout << wp1.moveTo(3) << endl;
    cout << w0.moveTo(2) << endl;
    cout << wp0.attackPlayer() << endl;
    cout << w1.attackPlayer() << endl;

    
    // // cout << c0.toString() << endl;
	// // cout << c1.toString() << endl;
    // // cout << c2.toString() << endl;
    // // cout << cp0.toString() << endl;
	// // cout << cp1.toString() << endl;
	cout << "**** FIN ****" << endl;
	cin.ignore();


}
/*
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


Capa neuronal id: 1
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