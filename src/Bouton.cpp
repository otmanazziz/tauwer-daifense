#include "Bouton.h"
#include <iostream>

Bouton::Bouton(){
	Vect v(0, 0);
	pos = v;
	taille = v;
}

Bouton::Bouton(const Bouton &_Bouton){
	nom = _Bouton.nom;
	pos = _Bouton.pos;
	taille = _Bouton.taille;
}

Bouton::Bouton(const std::string &_nom, const Vect &_pos, const Vect &_taille){
	nom = _nom;
	pos = _pos;
	taille = _taille;
}

Bouton::~Bouton(){
	nom = "";
	Vect v(0, 0);
	pos = v;
	taille = v;
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
	pos = _pos;
}

void Bouton::setTaille(const Vect &_taille){
	taille = _taille;
}

bool Bouton::clique(const Vect &_pos){
	if ((_pos.getX() >= (pos.getX() - taille.getX())) && (_pos.getX() <= (pos.getX() + taille.getX())) && (_pos.getY() >= (pos.getY() - taille.getY())) && (_pos.getY() <= (pos.getY() + taille.getY())))
		return true;
	return false;
}