#include <iostream>
using namespace std;

#include "Wumpus.h"
#include "WumpusPack.h"
#include "Cadejos.h"
#include "CadejosPack.h"
#include "Wolf.h"
#include "WolfPack.h"
#include "InvisibleMonster.h"
#include "ReplicableMonster.h"
#include "MonsterMemory.h"
int main()
{
    cout << "**** INICIO ****" << endl;

    cout << "**** Wumpuses ****" << endl;
    Wumpus w0, w1, w2;
    WumpusPack wp0, wp1;

    w0.addMonsterToPack(&wp0);
    w1.addMonsterToPack(&wp0);
    wp1.addMonsterToPack(&w2);

    cout << w0.toString() << endl;
    cout << w1.toString() << endl;
    cout << w2.toString() << endl;
    cout << wp0.toString() << endl;
    cout << wp1.toString() << endl;
    cout << wp1.moveTo(3) << endl;
    cout << w0.moveTo(2) << endl;
    cout << wp0.attackPlayer() << endl;
    cout << w1.attackPlayer() << endl;

    cout << "**** Cadejoss ****" << endl;
    Cadejos c0, c1, c2;
    CadejosPack cp0, cp1;

    c0.addMonsterToPack(&cp1);
    c1.addMonsterToPack(&cp1);
    cp0.addMonsterToPack(&c2);

    cout << c0.toString() << endl;
    cout << c1.toString() << endl;
    cout << c2.toString() << endl;
    cout << cp0.toString() << endl;
    cout << cp1.toString() << endl;
    cout << cp1.moveTo(3) << endl;
    cout << c0.moveTo(2) << endl;
    cout << cp0.attackPlayer() << endl;
    cout << c1.attackPlayer() << endl;

    cout << "Añadiendo invisibilidad a manada 0 y wumpus 2" << endl;
    InvisibleMonster invisiblePack0{wp0};
    cout << invisiblePack0.toString();
    InvisibleMonster invisibleWumpus{w2};
    cout << invisibleWumpus.toString();

    ReplicableMonster wumpusInvisibleReplicable{w2};
    cout << wumpusInvisibleReplicable.toString();
    cout << "añadiendo replicabilidad a la manada 0 " << endl;
    ReplicableMonster transparentReplicableWumpus{invisiblePack0};
    cout << transparentReplicableWumpus.toString();

    cout << "Añadiendo memoria a la manada 0 y la manada 1" << endl;
    MonsterMemory transparentReplicableMemoryPack{transparentReplicableWumpus};
    cout << transparentReplicableMemoryPack.toString();
    cout << "**** FIN ****" << endl;
    cin.ignore();
}
/*
**** INICIO ****
Wumpus #0

Wumpus #1

Wumpus #2

Manada de wumpus #0
Wumpus #0
Wumpus #1

Manada de wumpus #1
Wumpus #2

Wumpus 2 se mueve a 3

Wumpus 0 se mueve a 2

Wumpus 0 ataca a jugador.

Wumpus 1 ataca a jugador.

Cadejos #0

Cadejos #1

Cadejos #2

Manada de Cadejos #0
Cadejos #2

Manada de Cadejos #1
Cadejos #0
Cadejos #1

Cadejos 0 se mueve a 3
Cadejos 1 se mueve a 3

Cadejos 0 se mueve a 2

Cadejos 2 ataca a jugador.

Cadejos 1 ataca a jugador.

**** FIN ****




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