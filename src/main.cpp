#include <iostream>
#include <string>
#include "Vect.h"
#include "Tour.h"
#include "Base.h"
#include "Couleur.h"
#include "Bouton.h"

using namespace std;

int main(){
	Vect v1;
	Vect v2(100, 150);
	Vect v3(50, 20);
	Vect v4(10, 10);
	Vect v5(v2);
	v1 = v3;
	Vect v6 = v1 + v3;

	Bouton b;
	Bouton b1("Premier bouton", v2, v3);
	Bouton b2("Second bouton", v2, v4);
	Bouton b3(b1);

	Vect v7(50, 130);
	Vect v8(50, 170);
	Vect v9(150, 170);
	Vect v10(150, 130);

	Vect v11(140, 154);
	Vect v12(49, 131);

	if (b1.clique(v7)) cout << "Vrai.\n";
	else cout << "False.\n";
	if (b1.clique(v8)) cout << "Vrai.\n";
	else cout << "False.\n";
	if (b1.clique(v9)) cout << "Vrai.\n";
	else cout << "False.\n";
	if (b1.clique(v10)) cout << "Vrai.\n";
	else cout << "False.\n";
	if (b1.clique(v11)) cout << "Vrai.\n";
	else cout << "False.\n";
	if (b1.clique(v12)) cout << "Vrai.\n";
	else cout << "False.\n";


	return 0;
}