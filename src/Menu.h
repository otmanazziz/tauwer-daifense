#ifndef MENU
#define MENU

#include "Vect.h"
#include "Bouton.h"
#include <vector>
#include <iostream>

class Menu{
private:
	int nbBouton;
	std::vector<Bouton> tabBouton;
public:
	Menu();
	Menu(const Menu &_Menu);
	Menu(const int &_nbBouton, const std::vector<Bouton> &_tabBouton);
	~Menu();

	int getNbBouton();
	std::vector<Bouton> getTabBouton();

	void setNbBouton(const int &_nbBouton);
	void setTabBouton(const std::vector<Bouton> &_tabBouton);

	void setBoutonIndice(const int &indice, Bouton bouton);
	Bouton getBoutonIneice(const int &indice);

	void ajouterBouton(Bouton _bouton);
	void supprimerBoutonIndice(const int &indice);

	void afficherTabBouton();


};

#endif