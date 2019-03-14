#include "Base.h"
#include <iostream>

Base::Base(){	//Aucune affectation de coordonnées au constructeur.
	vie = 100;
}

Base::Base(const Vect &_position){
	position.setVect(_position);
}

Base::Base(const int &_vie, const Vect &_position){
	vie = _vie;
	position.setVect(_position);
}

Base::Base(const Base &_Base){
	vie = _Base.vie;
	position.setVect(_Base.position);
}
Base::~Base(){
	//DESTRUCTEUR
}

int Base::getVie(){
	return vie;
}

Vect Base::getPosition(){
	return position;
}

void Base::setVie(const int &_vie){
	vie = _vie;
}

void Base::setPosition(const Vect &_position){
	position.setVect(_position);
}

void Base::perdreVie(const int &viePerdue){
	if (vie - viePerdue <= 0) vie = 0;
	else vie -= viePerdue;
}