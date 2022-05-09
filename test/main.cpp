#include <iostream>
using namespace std;

#include "Bat_t.h"
#include "BatPack_t.h"

int main() {
	Bat n1, n2;
	BatPack nl1, nl2;

	n1.connect_to< Bat >(n2);
	n1.connect_to< BatPack>(nl1);
	nl2.connect_to< Bat >(n2);
	nl1.connect_to< BatPack>(nl2);

	cout << "**** INICIO ****" << endl;
	cout << n1.toString() << endl;
	cout << n2.toString() << endl;
	cout << nl1.toString() << endl;
	cout << nl2.toString() << endl;
	cout << "**** FIN ****" << endl;
	cin.ignore();
}