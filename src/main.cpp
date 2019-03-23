#include <iostream>
#include <string>

#include "Attaque.h"
#include "Base.h"
#include "Bouton.h"
#include "Carte.h"
#include "Chemin.h"
#include "Couleur.h"
#include "Effet.h"
#include "fonction.h"
#include "Hero.h"
#include "Menu.h"
#include "Monstre.h"
#include "Sort.h"
#include "Tour.h"
#include "Vague.h"
#include "Vect.h"
#include "Niveau.h"
#include "Jeu.h"
using namespace std;

int main(){

	//Couleur c1(10,20,30,40);
	//c1.testRegression();
	
	/*Vect v1;
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

	Effet e1;
	Effet e2(e1);
	Effet e3(12);
	e1.afficheEffet();
	e2.afficheEffet();
	e3.afficheEffet();
	e2.setValeur(45);
	e2.afficheEffet();

	Menu m;
	m.afficherTabBouton();
	m.ajouterBouton(b);
	m.ajouterBouton(b1);
	m.ajouterBouton(b2);
	m.afficherTabBouton();
	m.setBoutonIndice(1, b8);
	m.afficherTabBouton();*/
	
	//Carte c("test");
	//c.tourIndice(0).affiche();
	//c.vagueIndice(0).affiche();
	//c.cheminIndice(0).affiche();
	//Niveau niv("test");
	//niv.getCarte().tourIndice(0).affiche();
	Jeu j;
	j.afficheCarteDispo();
	j.getNiveau()->getCarte().addrTourIndice(0)->affiche();;
	Vect vTest;
	vTest.testRegression();
	return 0;
}