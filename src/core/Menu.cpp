#include "Menu.h"

Menu::Menu(){
	
}

Menu::Menu(const Menu &_Menu){
	tabBouton = _Menu.tabBouton;
}

Menu::Menu(const std::vector<Bouton> &_tabBouton){
	tabBouton = _tabBouton;
}

Menu::~Menu(){
	tabBouton.clear();
}

std::vector<Bouton> Menu::getTabBouton(){
	return tabBouton;
}

void Menu::setTabBouton(const std::vector<Bouton> &_tabBouton){
	tabBouton = _tabBouton;
}

void Menu::setBoutonIndice(const int &indice, Bouton bouton){
	tabBouton[indice].setNom(bouton.getNom());
	tabBouton[indice].setPos(bouton.getPos());
	tabBouton[indice].setTaille(bouton.getTaille());
}

Bouton Menu::getBoutonIndice(const int &indice){
	Bouton bouton;
	bouton.setNom(tabBouton[indice].getNom());
	bouton.setPos(tabBouton[indice].getPos());
	bouton.setTaille(tabBouton[indice].getTaille());
	return bouton;
}

void Menu::ajouterBouton(Bouton _bouton){
	tabBouton.push_back(_bouton);
}

void Menu::afficherTabBouton(){
	if (tabBouton.size() > 0){
		Vect _pos;
		Vect _taille;
		std::cout << "Vous avez actuellement " << tabBouton.size() << " boutons dans votre menu..\n";

		for (unsigned int i = 0; i < tabBouton.size(); i++){
			std::cout << "Affichage du bouton " << i << "\n";
			std::cout << tabBouton[i].getNom() << "\n";

			_pos = tabBouton[i].getPos();
			_taille = tabBouton[i].getTaille();

			std::cout << "Position : ";
			_pos.afficheVect();
			std::cout << "Taille : ";
			_taille.afficheVect();

			std::cout << "Fin de l'affichage du bouton " << i << "\n\n";
		}
		std::cout << "\n\n";
	} else std::cout << "Ce menu ne contient aucun bouton\n\n";
}

void Menu::supprimerBoutonIndice(const int &indice){
	tabBouton.erase(tabBouton.begin() + indice);
}

unsigned int Menu::getTaille(){
 return tabBouton.size();
}

//JE TERMINERAIS LE WE : OTMAN