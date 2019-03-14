#include <iostream>
#include "Vect.h"
#include "Tour.h"

using namespace std;

int main(){
	Vect v1;
	Vect v2(4, -6);
	Vect v3(v2);
	Vect v4 = v2 * v3;

	v1.afficheVect();
	v2.afficheVect();
	v3.afficheVect();
	v4.afficheVect();

	// Tour t1;
	// Tour t2(4.8, 5, v3);
	// Tour t3(t2);

	// t1.affiche();
	// t2.affiche();
	// t3.affiche();

	return 0;
}