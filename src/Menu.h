#ifndef MENU
#define MENU

#include "Vect.h"
#include "Bouton.h"
#include <vector>
#include <iostream>

class Menu{
private:
	std::vector<Bouton> tabBouton;
public:
	Menu();
	Menu(const Menu &_Menu);
	Menu(const std::vector<Bouton> &_tabBouton);
	~Menu();

	std::vector<Bouton> getTabBouton();

	void setTabBouton(const std::vector<Bouton> &_tabBouton);

	void setBoutonIndice(const int &indice, Bouton bouton);
	Bouton getBoutonIndice(const int &indice);

	void ajouterBouton(Bouton _bouton);
	void supprimerBoutonIndice(const int &indice);

	void afficherTabBouton();


};

#endif