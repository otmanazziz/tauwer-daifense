#include <iostream>
#include "Vect.h"
#include "Tour.h"
#include "Base.h"
#include "Couleur.h"

using namespace std;

int main(){
	// Vect v1;
	// Vect v2(4, -6);
	// Vect v3(v2);
	// Vect v4 = v2 * v3;

	// v1.afficheVect();
	// v2.afficheVect();
	// v3.afficheVect();
	// v4.afficheVect();

	// Tour t1;
	// Tour t2(4.8, 5, v3);
	// Tour t3(t2);

	// t1.affiche();
	// t2.affiche();
	// t3.affiche();

	// Base b1;
	// Base b2(150, v2);
	// cout << b2.getVie() << endl;
	// b2.perdreVie(50);
	// cout << b2.getVie() << endl;
	// b2.perdreVie(50);
	// cout << b2.getVie() << endl;
	// b2.perdreVie(50);
	// cout << b2.getVie() << endl;
	// b2.perdreVie(50);
	// cout << b2.getVie() << endl;

	cout << "Creation des couleurs c, c1, c2...\n";
	Couleur c;
	Couleur c1(150, 200, 42, 0.6);
	Couleur c2(800, 600, 400, 0.9);

	cout << "Affectation de c a c1, et de c1 a c2...\n";
	c = c1;
	c1 = c2;

	return 0;
}