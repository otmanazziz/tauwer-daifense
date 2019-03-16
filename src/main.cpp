#include <iostream>
#include <string>
#include "Vect.h"
#include "Tour.h"
#include "Base.h"
#include "Couleur.h"
#include "Bouton.h"
#include "Menu.h"

using namespace std;

int main(){
	
	Vect v1;
	Vect v2(100, 150);
	Vect v3(50, 20);
	Vect v4(10, 10);
	Vect v5(v2);
	Vect v7(50, 130);
	Vect v8(50, 170);
	Vect v9(150, 170);
	Vect v10(150, 130);
	Vect v11(140, 154);
	Vect v12(49, 131);

	Bouton b("Premier bouton", v1, v2);
	Bouton b1("Second bouton", v1, v3);
	Bouton b2("Troisieme bouton", v4, v12);
	Bouton b3("Quatrieme bouton", v4, v11);
	Bouton b4("Cinquieme bouton", v5, v10);
	Bouton b5("Sixieme bouton", v5, v11);
	Bouton b6("Septieme bouton", v7, v3);
	Bouton b7("Huitieme bouton", v8, v9);
	Bouton b8("Neuvieme bouton", v8, v12);
	
	Menu m;
	m.ajouterBouton(b);
	m.ajouterBouton(b1);
	m.ajouterBouton(b2);
	m.ajouterBouton(b3);
	m.ajouterBouton(b4);
	m.afficherTabBouton();
	m.supprimerBoutonIndice(1);
	m.supprimerBoutonIndice(2);
	m.supprimerBoutonIndice(1);

	m.afficherTabBouton();
	cout << "Allo\n";
	return 0;
}