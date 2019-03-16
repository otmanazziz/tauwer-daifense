#include "Menu.h"

Menu::Menu(){
	nbBouton = 0;
}

Menu::Menu(const Menu &_Menu){
	nbBouton = _Menu.nbBouton;
	tabBouton = _Menu.tabBouton;
}

Menu::Menu(const int &_nbBouton, const std::vector<Bouton> &_tabBouton){
	nbBouton = _nbBouton;
	tabBouton = _tabBouton;
}

Menu::~Menu(){
	nbBouton = 0;
	tabBouton.clear();
}

int Menu::getNbBouton(){
	return nbBouton;
}

std::vector<Bouton> Menu::getTabBouton(){
	return tabBouton;
}

void Menu::setNbBouton(const int &_nbBouton){
	nbBouton = _nbBouton;
}

void Menu::setTabBouton(const std::vector<Bouton> &_tabBouton){
	tabBouton = _tabBouton;
}

void Menu::setBoutonIndice(const int &indice, Bouton bouton){
	tabBouton[indice].setNom(bouton.getNom());
	tabBouton[indice].setPos(bouton.getPos());
	tabBouton[indice].setTaille(bouton.getTaille());
}

Bouton Menu::getBoutonIneice(const int &indice){
	Bouton bouton;
	bouton.setNom(tabBouton[indice].getNom());
	bouton.setPos(tabBouton[indice].getPos());
	bouton.setTaille(tabBouton[indice].getTaille());
	return bouton;
}

void Menu::ajouterBouton(Bouton _bouton){
	tabBouton.push_back(_bouton);
	nbBouton++;
}

void Menu::afficherTabBouton(){
	Vect _pos;
	Vect _taille;
	std::cout << "Vous avez actuellement " << nbBouton << " boutons dans votre menu..\n";
	for (int i = 0; i < nbBouton; i++){
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
}

void Menu::supprimerBoutonIndice(const int &indice){
	tabBouton.erase(tabBouton.begin() + indice);
	nbBouton --;
}

//JE TERMINERAIS LE WE : OTMAN