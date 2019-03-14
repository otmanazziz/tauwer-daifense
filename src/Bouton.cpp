#include "Bouton.h"
#include <iostream>

Bouton::Bouton(){
	Vect v(0, 0);
	pos.setVect(v);
	taille.setVect(v);
}

Bouton::Bouton(const Bouton &_Bouton){
	nom = _Bouton.nom;
	pos.setVect(_Bouton.pos);
	taille.setVect(_Bouton.pos);
}

Bouton::Bouton(const std::string &_nom, const Vect &_pos, const Vect &_taille){
	nom = _nom;
	pos.setVect(_pos);
	taille.setVect(_taille);
}

Bouton::~Bouton(){
	std::cout << "Le bouton a bien ete supprime...\n";
}

std::string Bouton::getNom(){
	return nom;
}

Vect Bouton::getPos(){
	return pos;
}

Vect Bouton::getTaille(){
	return taille;
}

void Bouton::setNom(const std::string &_nom){
	nom = _nom;
}

void Bouton::setPos(const Vect &_pos){
	pos.setVect(_pos);
}

void Bouton::setTaille(const Vect &_taille){
	taille.setVect(_taille);
}

bool Bouton::clique(const Vect &_pos){
	if ((_pos.getX() >= (pos.getX() - taille.getX())) && (_pos.getX() <= (pos.getX() + taille.getX())) && (_pos.getY() >= (pos.getY() - taille.getY())) && (_pos.getY() <= (pos.getY() + taille.getY())))
		return true;
	return false;
}