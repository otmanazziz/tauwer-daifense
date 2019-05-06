#include "Base.h"
#include <iostream>

Base::Base(){	//Aucune affectation de coordonnées au constructeur.
	vie = 0 ;
	position = Vect(0,0);
}

Base::Base(const int &_vie, const Vect &_position){
	std::cout<<"test"<<std::endl;
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

int Base::getVie()const{
	return vie;
}

Vect Base::getPosition()const{
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

void Base::affiche()const{
std::cout<<" Position : "<<std::endl;
	position.afficheVect();
std::cout<<" Vie : "<<vie <<std::endl;
}